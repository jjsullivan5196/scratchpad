import sys
al = ['@','8','(','|)','3','#','6','[-]','|','_|','|<','1','[]\\/[]','[]\\[]','0','|D','(,)','|Z','$',"']['",'|_|','\\/','\\/\\/','}{','`/','2']
r = range(65,91)
print(''.join([al[ord(c) - 65] if ord(c) in r else c for c in sys.stdin.readline().upper()]))
