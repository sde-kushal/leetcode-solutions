class Solution:
    def maximumEnergy(self, energy: List[int], k: int) -> int:
        n, max_energy = len(energy), -inf
        dp = [0]*n

        for i in range(n-1,-1,-1):
            collected_energy = dp[i+k] if i+k<n else 0
            dp[i] = energy[i] + collected_energy
            max_energy = max(max_energy, dp[i])

        return max_energy