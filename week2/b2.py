def isBalanced(s):
    stack = []
    right = {'}':'{',')':'(',']':'['}
    left = ['(','{','[']
    for c in s:
        if c in left:
            stack.append(c)
        else:
            if len(stack) > 0 and stack[-1] == right[c]:
                stack.pop()
            else:
                return 'NO'
    if len(stack) > 0:
        return 'NO'
    return 'YES'