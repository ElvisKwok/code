#!/usr/bin/env python
# coding: utf-8 

#edward = ['Edward Gumby', 42]
#john = ['John Smith', 50]
#database = [edward, john]
#print database

#months = [
#    'January',
#    'February',
#    'March',
#    'April',
#    'May',
#    'June',
#    'July',
#    'August',
#    'September',
#    'October',
#    'November',
#    'December'
#]
#
#endings = ['st', 'nd', 'rd'] + 17 * ['th'] \
#        + ['st', 'nd', 'rd'] + 7 * ['th'] \
#        + ['st']
#
#year    = raw_input("Year: ")
#month   = raw_input("Month (1-12):")
#day     = raw_input("Day (1-31):")
#
#month_number = int(month)
#day_number = int(day)
#
#month_name = months[month_number-1]
#ordinal = day + endings[day_number-1]
#
#print month_name + ' ' + ordinal + ', ' + year

#sequence = [None] * 10
#print sequence

#sentence = raw_input("Sentence: ")
#
#screen_width = 80
#text_width = len(sentence) 
#box_width = text_width + 6
#left_margin = (screen_width - box_width) // 2
#
#print 
#print ' ' * left_margin + '+'  + '-' * (box_width-4) + '+'
#print ' ' * left_margin + '| ' + ' ' * text_width    + ' |'
#print ' ' * left_margin + '| ' +       sentence      + ' |'
#print ' ' * left_margin + '| ' + ' ' * text_width    + ' |'
#print ' ' * left_margin + '+'  + '-' * (box_width-4) + '+'
#print 


database = [
    ['Elvis', '1234'],
    ['Smith', '2313'],
    ['Jones', '3434']
]

username = raw_input("User name: ")
password = raw_input("Password: ")

if [username, password] in database: 
    print 'Access granted'
else:
    print 'Denied'
