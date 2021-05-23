class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        result = []

        def recurse(currentPath, currentCount, index):
            if index == len(candidates) :
                return

            if currentCount - candidates[index] <= 0 :
                if currentCount - candidates[index] == 0 :
                    result.append(currentPath + [candidates[index]])
                return

            recurse(currentPath + [candidates[index]], currentCount - candidates[index], index)
            recurse(currentPath, currentCount, index + 1)

        recurse([], target, 0)
        return result
