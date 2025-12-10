txt = open("data.csv").read()

def load():
    return txt


csv = map(lambda x: x.split(","), txt.split("\n"))
print(list(csv))


txt.join(',')

print(csv)