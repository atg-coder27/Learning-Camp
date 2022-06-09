
t = int(input())
for _ in range(t):
    n, k, f = map(int, input().split())
    arr = []
    for i in range(n):
        l, r = map(int, input().split())
        arr.append([l, r])
    stack = []
    arr.sort()
    for i in range(n):
        if len(stack) == 0:
            stack.append(arr[i])
        else:
            l, r = stack[-1]
            ql, qr = arr[i]
            if ql > r:
                stack.append(arr[i])
            else:
                left = l
                right = max(r, qr)
                stack.pop()
                stack.append([left, right])
    st = 0
    count = 0
    for i in stack:
        count += i[0]-st
        st = i[1]

    if len(stack) == 0:
        pass
    else:
        count += f-stack[-1][1]

    if count >= k:
        ans = "YES"
    else:
        ans = "NO"
    print(ans)
