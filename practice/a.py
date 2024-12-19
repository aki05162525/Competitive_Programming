S = input()

count = 0

# 9 文字の式に限定していることに注意
for i in range(9):
    if S[i] == "1":
        count += 1

print(count)
