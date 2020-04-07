
t= int(input())
for o in range(1,t+1):
    # print(t)
    n = int(input())
    starts = []
    ends =[]
    answer = []
    indexs=[]
    cstart = -100
    cend = -100
    jstart= -100
    jend= -100
    imp=0
    for i in range(0,n):
        v = input()
        l = v.split()
        starts.insert(i, int(repr(int(l[0]))))
        ends.insert(i, int(repr(int(l[1]))))
        indexs.insert(i, i)
    
    for y in range(0,n):
        answer.insert(y, 0)

    for i in range(n) : 
        for j in range(0, n-i-1): 
            if starts[j] > starts[j+1] : 
                ends[j], ends[j+1] = ends[j+1], ends[j] 
                starts[j], starts[j+1] = starts[j+1], starts[j]
                indexs[j], indexs[j+1] = indexs[j+1], indexs[j]
                
    for i in range(0,n):
        if(i==0):
            cstart = int(starts[0])
            cend = int(ends[0])
            answer[i] = -20
        elif(cend<=int(starts[i])):
            cstart = int(starts[i])
            cend = int(ends[i])
            answer[i] = -20
        elif(jend<=int(starts[i])):
            jstart = int(starts[i])
            jend = int(ends[i])
            answer[i] = -10
        else:
            imp = 1
            
    for i in range(n):
        temp=0
        for j in range(0,n-i-1):
            if (indexs[j] > indexs[j+1]):
                ends[j], ends[j+1] = ends[j+1], ends[j]
                starts[j], starts[j+1] = starts[j+1], starts[j]
                indexs[j], indexs[j+1] = indexs[j+1], indexs[j]
                answer[j], answer[j+1] = answer[j+1], answer[j]
    
    print("Case #", end='')
    print(str(o), end='')
    print(":", end=' ')
    if(imp==0):
        for i in range(0,n):
            if answer[i] == (-10):
                print("J", end='')
            elif answer[i] == (-20):
               print("C", end='')
        print()
    elif (imp == 1):
        print("IMPOSSIBLE")
