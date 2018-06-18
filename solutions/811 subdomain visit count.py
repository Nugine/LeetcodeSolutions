class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        d = dict()
        for cpd in cpdomains:
            cnt, dm = cpd.split(' ')
            cnt=int(cnt)
            d.setdefault(dm, 0)
            d[dm] += cnt
            for _ in range(len(dm.split('.')) - 1):
                dm = dm[dm.index('.') + 1:]
                d.setdefault(dm, 0)
                d[dm] += cnt
        return [str(cnt) + ' ' + dm for dm, cnt in d.items()]
