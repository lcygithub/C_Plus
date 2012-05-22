#-*- coding:utf8-*-
import time
import os
import sys
start = time.time()
#print sys.argv
os.system("iconv -f=gb2312 -t=utf8 " +sys.argv[1]+" -o "+sys.argv[1])
print "耗时："+str(time.time() - start)