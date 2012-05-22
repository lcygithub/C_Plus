#-*- coding:utf8 -*-
import os
import sys
import datetime
in_file = sys.argv[1]
out_file = sys.argv[2]
print "源文件：" + in_file
print "输出文件：" + out_file
fin = open(in_file,"r+")
fout = open(out_file,"a+")   #打开 输出文件
key1 = "行 数"                #输入当前行号
key2 = "关键字"               #输入关键字
key3 = "    源代码"           #输入关键字
keys =  key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + "\n" #标准打印
fout.write(keys)             #写入 keys
fout.close()                 #关闭输出文档
key = ["if","else","for","while","do","int","read","write"] #保留字
number = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
singleword = ["+","-","*","/","(",")","{","}",";",",",":","%"]   #单分界符号
doubleword = [">","<","=","!"]                              #双分界符号
control_cycle_key = ["for","if","while"]                    #控制 循环的关键字
operator_key = ["+","-","*","/","="]
err = key + number + singleword + doubleword
ch = ""
token = ""
errors = 0
strs = fin.read()
fin.seek(0)
line = fin.readlines()
fin.seek(0)
print "源程序共：" + str(len(line)) + "行 " + str(len(strs)) + "个字符"
line_i = 1                               #初始行号为 1
ch = fin.read(1)                         #ch指针 继续读下一个ch
def reverse_str(string): 
    return string[::-1]
while fin.tell() < len(strs) :
    while ch == "\n":
        line_i += 1
        ch = fin.read(1)                 #ch指针 继续读下一个ch
    while ch == " " or ch == "\t" :      #如果读到了 空格 或者 "\t"
        ch = fin.read(1)                 #ch指针 继续读下一个ch
    if ch.isalpha():                     #如果 ch 是字母
        token += ch                      #将ch 填进 token
        ch = fin.read(1)                 #继续读下一个ch
        while ch.isalnum() :             #如果是 字母或者数字
            token += ch                  #将ch 填进 token
            ch = fin.read(1)             #继续读下一个ch
        if token in key :                #如果token是关键字
            fout = open(out_file,"a+")   #打开 输出文件
            key1 = "第" + str(line_i) + "行"           #输入当前行号
            key2 = token                 #输入关键字
            key3 = token                 #输入关键字
            keys =  key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + "\n" #标准打印
            fout.write(keys)             #写入 keys
            fout.close()                 #关闭输出文档
            token = ""                   #将token 置空
        else :                           #如果token不是关键
            fout = open(out_file,"a+")   #打开 输出文件
            key1 = "第" + str(line_i) + "行"           #输入当前行号
            key2 = "ID"                  #打印 ID
            key3 = token                 #输入标识符
            keys =  key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + "\n"#标准打印
            fout.write(keys)             #写入
            fout.close()                 #关闭 
            token = ""                   #token 置空
    elif ch in number :                  #如果ch是数字
        verify = "yes"
        token += ch                      #token 填入 ch
        ch = fin.read(1)                 #继续读下一个ch 
        error = ""                       #错误信息
        while ch in number :             #如果下一个仍是 数字
            token += ch                  #token 填入 ch
            ch = fin.read(1)             #继续读下一个ch
        while ch.isalpha() :
            if not ch in number :
                token += ch
                ch = fin.read(1)
                verify = "no"
            else:
                break
        fout = open(out_file,"a+")       #打开 输出文件
        key1 = "第" + str(line_i) + "行"  #输入当前行号
        if verify == "yes":
            key2 = "NUM"                 #写入 NUM
        elif verify == "no":
            key2 = "ERROR" 
            error = "标识符必须以字母开头"
            errors += 1
        key3 = token                     #写入标识符
        keys =  key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ") + "\n"#标准打印
        fout.write(keys)                 #写入
        if verify == "no":
            print key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ")
        fout.close()                     #关闭文件
        token = ""                       #置空
    elif ch in singleword:               #如果 ch 是单分界符
        token += ch                      #token 填入 ch
        token_negtive = token            # 判定负数
        token_headerr = token            # 判定非字母开头的标识符号
        pos = fin.tell()                 #记录判断时候是负数的指针位置
        pre_pos  = pos - 2               #向前 查看 前2个字符是否是字符 “=” 的文件指针 开始指向 当前位置
        is_pre_notequal = False          #“-”号前是 等号 为真
        is_last_num = False              #"-"号后面是不是数字
        is_comment = False               #不是注释
        is_error_head = False            #不是错误的标识符
        is_control_quote = False         #不是运算符中的括号
        control_cycle_token = ""
        err_head = ""
        pre_err_head = ""
        if ch == "/":                    #如果是"/" 便有能是注释
            ch = fin.read(1)             # 等于 * 
            if fin.tell() >= len(strs):
                break            
            if ch == "*" :
                ch = fin.read(1)         # *后面的 
                while ch != "*":
                    if fin.tell() >= len(strs):
                        break
                    ch = fin.read(1)     # 等于 *
                ch = fin.read(1)             # 等于 /
                if fin.tell() >= len(strs):
                    break
                if ch == "/":
                    is_comment = True
                    ch = fin.read(1)         #读/下一个
                    if fin.tell() >= len(strs):
                        break
        elif ch == "*" or ch == "+":
            pos = fin.tell()
            pre_pox = pos - 2
            err_head += ch
            ch = fin.read(1)
            while ch != ";" and ch != " ":
                err_head += ch 
                ch = fin.read(1)
            last_pos = fin.tell()
            fin.seek(pre_pos)
            ch = fin.read(1)
            while ch == " ":
                pre_pos -= 1
                fin.seek(pre_pos)
                ch = fin.read(1)
            pre_err_head += ch
            while ch.isalpha():
                 pre_pos -= 1
                 fin.seek(pre_pos)
                 ch = fin.read(1)
                 if ch.isalpha():
                    pre_err_head += ch
            if str(reverse_str(pre_err_head)) == "int":
                fin.seek(last_pos - 1)
                ch = fin.read(1)
                is_error_head = True
                fout = open(out_file,"a+")
                key1 = "第" + str(line_i) + "行"   #输入当前行号   
                key2 = "ERROR"                    #打印关键字
                key3 =  err_head                  #打印关键字
                error = "标识符只能以字母开头"
                keys = key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ") + "\n"
                print key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ")
                fout.write(keys)                  #写入
                fout.close()                      #关闭文件
                err_head = ""                        #token 置空
                errors += 1                       #错误数加一 
                pre_err_head = ""
            else:
                fin.seek(pos)
                ch = fin.read(1)
#        elif ch == "(":
#            pos = fin.tell()
#            pre_pos = pos - 2
#            fin.seek(pre_pos)
#            ch = fin.read(1)
#            while ch == " ":
#                pre_pos -= 1
#                fin.seek(pre_pos)
#                ch = fin.read(1)
#            if ch not in operator_key:
#                control_cycle_token += ch
#                while ch != " ":
#                    pre_pos -= 1
#                    fin.seek(pre_pos)
#                    ch = fin.read(1)
#                    control_cycle_token += ch
#                fin.seek(pos)
#                ch = fin.read(1)
#                while ch != ")":
#                    ch = fin.read(1)
#                ch = fin.read(1)
#                if ch not in operator_key:
#                    is_control_quote = True
#                    if control_cycle_token not in control_cycle_key:
#                        fout = open(out_file,"a+")
#                        key1 = "第" + str(line_i) + "行"   #输入当前行号   
#                        key2 = "ERROR"                    #打印关键字
#                        key3 = control_cycle_token + "("  #打印关键字
#                        error = '''"()"前的标识符''' + '''"'''+control_cycle_token+'''"''' + '''不是控制或循环关键字'''
#                        keys = key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ") + "\n"
#                        print key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ")
#                        fout.write(keys)                  #写入
#                        fout.close()                      #关闭文件
#                        token = ""                        #token 置空
#                        errors += 1                       #错误数加一
#            elif is_control_quote == False:
#                fin.seek(pos)
#                ch = fin.read(1)
        elif ch == "-":       #如果读如一个 “ - ” 号 就进入 判定是否为负数
            ch = fin.read(1)             #继续读下一个ch
            while ch == " ":             #如果ch是空格
                ch = fin.read(1)         #继续读下一个ch 知道读到一个 不是 空格的 ch
            while ch in number:          #如果 ch 是数字
                token_negtive += ch      #token 填入 ch
                ch = fin.read(1)         #继续读下一个ch  直到 ch 不是数字
                is_last_num = True       #将 is_last_num 负数 last 判定符 置真
            if is_last_num == True:      #如果 后边 是数字 就把指针迁移 判断是否有等号
                pos_num = fin.tell()     #将文件指针指向最后非数字的位置
                fin.seek(pre_pos)        #将文件指针指向 "-" 所在前2个位置
                ch = fin.read(1)             #ch读取下一个位置字符 即负号前的位置
                while ch == " ":             #当ch 等于 空格
                    pre_pos -= 1             #定位指针向前 移动一次
                    fin.seek(pre_pos)        #将文件指针指向前1个位置
                    ch = fin.read(1)         #继续读下一个ch 直到 ch 不是空格
                if ch == "=":                #如果 “-“ 号前一个不是“=”
                    is_pre_notequal = True   #那么 不是等号 标记 为真
                fin.seek(pos_num - 1)        #把指针指向 pos_num 的前一位
                ch = fin.read(1)             #ch 读取 pos_num 那一位字符
        else:                                #如果不是负号
            ch = fin.read(1)
        if is_last_num and is_pre_notequal:  #如果 是负数 并且不是表达式
            fout = open(out_file,"a+")
            key1 = "第" + str(line_i) + "行"   #输入当前行号   
            key2 = "ERROR"                    #打印关键字
            key3 = token_negtive              #打印关键字
            error = "NUM 必须是无符号整数"
            keys = key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ") + "\n"#标准输出
            print key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ")
            fout.write(keys)                  #写入
            fout.close()                      #关闭文件
            token = ""                        #token 置空
            errors += 1                       #错误数加一
        else:
            if not is_comment and not is_error_head and not is_control_quote:                                 
                fout = open(out_file,"a+")
                key1 = "第" + str(line_i) + "行"  #输入当前行号   
                key2 = token                     #打印关键字
                key3 = token                     #打印关键字
                keys = key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + "\n"#标准输出
                fout.write(keys)                 #写入
                fout.close()                     #关闭文件
            token = ""                       #token 置空
    elif ch in doubleword:                   #如果ch是双分界符号
        token += ch                          #token 填入 ch
        pos = fin.tell()
        if token == "-" :
            ch = fin.read(1)
        ch = fin.read(1)                 #继续读下一个ch
        if ch == "=":                    #如果 下一个ch 是 “=”
            token += "="                 #token 填入 ch
            ch = fin.read(1)             #继续读下一个ch
        fout = open(out_file,"a+")
        key1 = "第" + str(line_i) + "行"               #输入当前行号   
        key2 = token                     #打印关键字
        key3 = token                     #打印关键字
        keys =  key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + "\n"#标准打印
        fout.write(keys)
        fout.close()
        token = ""
    elif list(ch) == []:
        ch = fin.read(1)
        line_i += 1
    else:
        token += ch
        ch = fin.read(1)
        fout = open(out_file,"a+")
        key1 = "第" + str(line_i) + "行"                #输入当前行号   
        key2 = "ERROR"                                 #打印关键字
        key3 = token                                   #打印关键字
        error = '''"''' + token + '''"'''+ "是非法字符"
        keys =  key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ") + "\n"#标准打印
        print key1.ljust(12," ") + key2.ljust(10," ") + key3.ljust(10," ") + error.ljust(30," ")
        fout.write(keys)
        fout.close()
        token = ""
        errors += 1
fin.close()
keys = "词法分析时间：" + str(datetime.datetime.now())
print keys
fout = open(out_file,"a+")
fout.write(keys)
fout.close()
if errors > 0 :
    print "词法分析完毕！" + "成功 0 失败 1," + "共 " + str(errors) + " 处错误！"
else :
    print "词法分析完毕！" + "成功 1 失败 0 无错误！"
