#!/usr/bin/env python
# coding: utf-8 

from xmlrpclib import ServerProxy, Fault
from client import randomString
from server import Node, UNHANDLED
from threading import Thread
from time import sleep
from os import listdir
import sys
import wx

HEAD_START = 0.1 # secs
SECRET_LENGTH = 100

class ListableNode(Node):
    """
    Node的扩展版本(子类)，可以列出文件目录中的文件
    """
    def list(self):
        return listdir(self.dirname)

class Client(wx.App):
    """
    主client类，用于设定GUI，启动为文件服务的Node
    """
    def __init__(self, url, dirname, urlfile):
        """
        创建一个随机密码，使用这个密码实例化Node。
        利用Node的_start方法启动Thread
        (确保Thread是个无交互的后台程序，随程序退出而退出)
        读取URL文件的所有URL，并将Node介绍给这些URL
        """
        self.secret = randomString(SECRET_LENGTH)
        n = ListableNode(url, dirname, self.secret)
        t = Thread(target=n._start)
        t.setDaemon(1)
        t.start()
        # server start first
        sleep(HEAD_START)
        self.server = ServerProxy(url)
        for line in open(urlfile):
            line = line.strip()
            self.server.hello(line)
        # 运行GUI
        super(Client, self).__init__()
    
    def updateList(self):
        """
        使用从服务器Node获得的文件名更新列表框
        """
        self.files.Set(self.server.list())

    def OnInit(self):
        """
        设置GUI。创建窗体、文本框和按钮，并进行布局。
        将提交按钮绑定到self.fetchHandler上
        """
        win = wx.Frame(None, title="File Sharing Client", size=(400,300))
        bkg = wx.Panel(win)

        self.input = input = wx.TextCtrl(bkg)
        
        submit = wx.Button(bkg, label="Fetch", size=(80, 25))
        submit.Bind(wx.EVT_BUTTON, self.fetchHandler)

        hbox = wx.BoxSizer()
        hbox.Add(input, proportion=1, flag=wx.ALL|wx.EXPAND, border=10)
        hbox.Add(submit, flag=wx.TOP|wx.BOTTOM|wx.RIGHT, border=10)

        self.files = files = wx.ListBox(bkg)
        self.updateList()

        vbox = wx.BoxSizer(wx.VERTICAL)
        vbox.Add(hbox, proportion=0, flag=wx.EXPAND)
        vbox.Add(files, proportion=1, flag=wx.EXPAND|wx.LEFT|wx.RIGHT|wx.BOTTOM, border=10)

        bkg.SetSizer(vbox)
        win.Show()
        
        return True

    def fetchHandler(self, event):
        """
        在用户点击'Fetch'按钮时调用。
        读取文本框中的查询，调用服务器Node的fetch方法。
        处理查询后，调用updateList.
        如果查询没有被处理则打印错误信息。
        """
        query = self.input.GetValue()
        try:
            self.server.fetch(query, self.secret)
            self.updateList()
        except Fault,f:
            if f.faultCode != UNHANDLED: 
                raise
            print "couldn't find the file", query

def main():
    urlfile, directory, url = sys.argv[1:]
    client = Client(url, directory, urlfile)
    client.MainLoop()

if __name__ == '__main__': 
    main()
