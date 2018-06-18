kls = [set('QWERTYUIOPqwertyuiop'),
       set('ASDFGHJKLasdfghjkl'),
       set('ZXCVBNMzxcvbnm')
       ]


def is_kl_word(word):
    for kl in kls:
        for c in word:
            if c not in kl:
                break
        else:
            return True
    return False


class Solution:
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        return [w for w in words if is_kl_word(w)]


# print(Solution().findWords(["Hello", "Alaska", "Dad", "Peace"]))
