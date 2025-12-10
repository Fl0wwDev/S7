#chargement donnée
txt = open("data.csv").read()

def load():
    return txt


csv = map(lambda x: x.split(","), txt.split("\n"))
text2 = "\n".join(map(lambda x: ",".join(x), csv))

#ensemble

if "ensisa" in txt:
    print("ok")


s1 = [1,2,3]
s2 = [3,4,5]
s3 = []

def intersect():
    for e in s1:
        if e in s2:
            s3 += [e]
    return s3

def difference():
    r = []
    for e in s1:
        if not (e in s2):
            r += [e]
    return r 

def union():
    return 
