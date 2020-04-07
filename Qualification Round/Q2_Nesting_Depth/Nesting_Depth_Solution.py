def op_str(num):
    p = ''
    for i in range(0,num):
        p+='('
    return p
def cl_str(num):
    p = ''
    for i in range(0,num):
        p+=')'
    return p
testCases = int(input())
for t in range(0,testCases):
    b_open='('
    b_close=')'
    already_open =0
    out_string = ''
    number = str(input())
    for i in range(0,len(number)):
        if(already_open>=int(number[i])):
            out_string+=cl_str(already_open- int(number[i]))+number[i]
            already_open -=(already_open - int(number[i]))
        else:
            if(already_open<int(number[i])):
                out_string+=op_str(int(number[i])-already_open)+number[i]
                already_open +=(int(number[i])- already_open)

    out_string += cl_str(already_open)
    lm = "Case #"+str(t+1)+":"
    print(lm,out_string)