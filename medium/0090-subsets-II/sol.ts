function subsetsWithDup(nums: number[]): number[][] {
    let items: Set<string> = new Set()
    items.add('[]')

    let subsets: number[][] = []

    for(let num of nums) {
        for(let item of items) 
            subsets.push([...JSON.parse(item), num].sort())

        for(let subset of subsets)
            items.add(JSON.stringify(subset))

        subsets = []
    }

    for(let item of items)
        subsets.push(JSON.parse(item))

    return subsets
}