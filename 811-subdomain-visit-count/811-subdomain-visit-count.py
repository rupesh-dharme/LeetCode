class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        dom_count = {}
        for entry in cpdomains:
            no, dom = entry.split()
            no = int(no)
            doms = dom.split(".")
            while (len(doms)):
                if dom_count.get(".".join(doms)):
                    dom_count[".".join(doms)] += no
                else:
                    dom_count[".".join(doms)] = no
                doms.pop(0)
        l = []
        for k, v in dom_count.items():
            l.append(str(v) + " " + k)
        return l