class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        if len(digits) == 0 :
            return []

        nc_map = {
            '2' : ['a', 'b', 'c'],
            '3' : ['d', 'e', 'f'],
            '4' : ['g', 'h', 'i'],
            '5' : ['j', 'k', 'l'],
            '6' : ['m', 'n', 'o'],
            '7' : ['p', 'q', 'r', 's'],
            '8' : ['t', 'u', 'v'],
            '9' : ['w', 'x', 'y', 'z']
        }

        def backtrack(index: int) :
            if index == len(digits) :
                combinations.append("".join(combination))
                return
            for c in nc_map[digits[index]] :
                combination.append(c)
                backtrack(index + 1)
                combination.pop()

        combinations = []
        combination = []
        backtrack(0)

        return combinations

