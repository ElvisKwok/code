#!/usr/bin/env python
# coding: utf-8 

#import wx
#
#def load(event):
#    file = open(filename.GetValue())
#    contents.SetValue(file.read())
#    file.close()
#
#def save(event):
#    file = open(filename.GetValue(), 'w')
#    file.write(contents.GetValue())
#    file.close()
#
#app = wx.App()
##窗口(Frame)，第一个参数为“父部件”，单独窗口=None
#win = wx.Frame(None, title="Simple Editor", size=(410,335))
#bkg = wx.Panel(win) #背景组件
#
#
#loadButton = wx.Button(bkg, label='open')
##loadButton = wx.Button(win, label='open', 
##                       pos=(225,5), size=(80,25))
#saveButton = wx.Button(bkg, label='save')
##saveButton = wx.Button(win, label='save',
##                       pos=(315,5), size=(80,25))
#
#loadButton.Bind(wx.EVT_BUTTON, load)
#saveButton.Bind(wx.EVT_BUTTON, save)
#
## 文本控件text control
#filename = wx.TextCtrl(bkg)
#contents = wx.TextCtrl(bkg,style=wx.TE_MULTILINE | wx.HSCROLL)
##filename = wx.TextCtrl(win, pos=(5,5), size=(210,25))
##contents = wx.TextCtrl(win, pos=(5,35), size=(390,260),
##                       style=wx.TE_MULTILINE | wx.HSCROLL)
#
## 尺寸器sizer
#hbox = wx.BoxSizer() # 默认为水平
#hbox.Add(filename, proportion=1, flag=wx.EXPAND)
#hbox.Add(loadButton, proportion=0, flag=wx.LEFT, border=5)
#hbox.Add(saveButton, proportion=0, flag=wx.LEFT, border=5)
#
#vbox = wx.BoxSizer(wx.VERTICAL)
#vbox.Add(hbox, proportion=0, flag=wx.EXPAND | wx.ALL, border=5)
#vbox.Add(contents, proportion=1, 
#         flag=wx.EXPAND | wx.LEFT | wx.BOTTOM | wx.RIGHT, border=5)
#
#bkg.SetSizer(vbox)
#
#win.Show()
#
#app.MainLoop()


import wx
def hello(event):
    print "hello world"

app = wx.App()
win = wx.Frame(None, title="wxpython",size=(200,100))
button = wx.Button(win,label="hello")
button.Bind(wx.EVT_BUTTON, hello)
win.Show()
app.MainLoop()
