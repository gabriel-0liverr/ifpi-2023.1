import threading, time, os
from prettytable import PrettyTable

table = PrettyTable(['Task 01', 'Task 02'])

def task_01():
    x = 0
    while x < 10:
        row = ['< Task 01 -- {}% >'.format(x * 10), '']
        table.add_row(row)
        
        os.system('cls' if os.name == 'nt' else 'clear')
        print(table)

        time.sleep(0.5)
        x += 1
    row = ['< Task 01 -- 100% >', '']
    table.add_row(row)

    os.system('cls' if os.name == 'nt' else 'clear')
    print(table)

def task_02():
    x = 0
    while x < 10:
        row = ['', '< Task 02 -- {}% >'.format(x * 10)]
        table.add_row(row)
        
        os.system('cls' if os.name == 'nt' else 'clear')
        print(table)

        time.sleep(0.25)
        x += 1
    row = ['', '< Task 02 -- 100% >']
    table.add_row(row)

    os.system('cls' if os.name == 'nt' else 'clear')
    print(table)


threading.Thread(target=task_01).start()
threading.Thread(target=task_02).start()