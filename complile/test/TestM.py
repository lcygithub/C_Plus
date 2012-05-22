#!/usr/bin/python
#! -*- coding: utf8 -*-

#class Symbols(dict):
#    def __getitem__(self,key):
#        if key in self:
#            #print "symbols"
#            #print dict.__getitem__(self,key)
#            return dict.__getitem__(self,key)
#        else:
#            return 0
            
class TestM(object):
    #make a self.codes and self.labels
    def __init__(self,src):
        codes = map(lambda x:x.split(),src.split('\n'))
        self.codes = []
        self.labels = {}
        idx = 0
        for code in codes:
            print idx,code
            if len(code) == 0:
                continue
            elif len(code) == 1:
                if code[0][:5] == 'LABEL':
                    self.labels[int(code[0][5:])] = idx
                else:
                    self.codes.append((code[0],None))
                    idx += 1
            else:
                if code[0] in ('BR','BRF'):
                    self.codes.append((code[0],int(code[1][5:])))
                else:
                    self.codes.append((code[0],int(code[1])))
                idx += 1
    def run(self):
        stack = []
        symbols = {}
        idx = 0
        while True:
            opt,src = self.codes[idx]
#            print idx,opt,src
            if opt == 'LOAD':
                stack.append(symbols[src])
            elif opt == 'LOADI':
                stack.append(src)
            elif opt == 'STO':
                symbols[src] = stack[-1]
            elif opt == 'STI':
                symbols[src] = stack.pop()
            elif opt == 'ADD':
                stack.append(stack.pop()+stack.pop())
            elif opt == 'SUB':
                stack.append(-(stack.pop()-stack.pop()))
            elif opt == 'MULT':
                stack.append(stack.pop()*stack.pop())
            elif opt == 'DIV':
                a,b = stack.pop(),stack.pop()
                stack.append(b/a)
            elif opt == 'MOD':
                a,b = stack.pop(),stack.pop()
                stack.append(b%a)
            elif opt == 'BR':
                idx = self.labels[src]
                continue
            elif opt == 'BRF':
                if not stack[-1]:
                    idx = self.labels[src]
                    continue
            elif opt in ('EQ','NOTEQ','GT',
                        'LES','GE','LE'):
                opts = {
                        'EQ':lambda a,b:a==b,'NOTEQ':lambda a,b:a!=b,
                        'GT':lambda a,b:a>b,'GE':lambda a,b:a>=b,
                        'LES':lambda a,b:a<b,'LE':lambda a,b:a<=b
                    }
                b,a = stack.pop(),stack.pop()
                stack.append(opts[opt](a,b))
            elif opt == 'IN':
                stack.append(int(raw_input('input a number: ')))
            elif opt == 'OUT':
                num = stack.pop()
                if num > 65535:
                    print "Waring:result out of indexout of 'int'\n"
                print num
            elif opt == 'STOP':
                break
            idx += 1

if __name__ == '__main__':
    import sys
    if len(sys.argv) != 2:
        src = []
        while True:
            try:
                src.append(raw_input())
            except EOFError:
                break
        src = '\n'.join(src)
    else:
        with file(sys.argv[1]) as f:
            src = f.read()
    TestM(src).run()
