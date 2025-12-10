#chargement donnée
txt = open("data.csv").read()

def load():
    return txt


csv = map(lambda x: x.split(","), txt.split("\n"))
text2 = "\n".join(map(lambda x: ",".join(x), csv))

#ensemble

if "ensisa" in txt:
    print("ok")


s1 = {1,2,3}
s2 = {3,4,5}

print(s1.intersection(s2))
print(s1.difference(s2))
print(s1.union(s2))