import json, time, os
from prettytable import PrettyTable

table = PrettyTable([' '])

tasks = []

def round_robin():
    count_time = 1
    # Ordena as tasks por prioridade(Do Maior ao Menor)
    tasks_ordered = sorted(tasks, key=lambda x: x['priority'], reverse=True)

    while len(tasks_ordered) > 0:
        # Exibe a Linha do Tempo
        #os.system('cls' if os.name == 'nt' else 'clear')
        print(table)
        print(tasks_ordered)

        '''
        # Filtrar tasks que ainda estão a executar
        tasks_active = list(filter(lambda x: x['duration'] > 0, tasks_ordered))

        # Filtrar tasks que já ingressaram
        tasks_started = list(filter(lambda x: x['ingress'] >= count_time, tasks_active))
        '''

        # Obtém a próxima tarefa
        current_task = tasks_ordered[0]

        if current_task['ingress'] <= count_time and current_task['duration'] > 0:
            # Executa a tarefa pelo quantum de 15 unidades de tempo ou até sua duração acabar
            for _ in range(15):
                if current_task['duration'] <= 0:
                    break

                # Adicionar coluna
                new_column = ["O" if id == current_task['id'] else "-" for id in range(len(tasks))]
                table.add_column(str(count_time), new_column)
                
                current_task['duration'] -= 1
                count_time += 1
                time.sleep(0.5)

            # Verifica se a tarefa ainda possui duração restante
            if current_task['duration'] > 0:
                print('ainda tem')
                # Move a tarefa para o final da lista
                tasks_ordered.append(tasks_ordered.pop(0))
            else:
                print('acabou')
                # Remove a tarefa da lista, pois sua duração acabou
                tasks_ordered.pop(0)
        else:
            new_column = [" " for _ in range(len(tasks))]
            count_time += 1
            time.sleep(0.5)

    print('__________________________________')
    input('Pressione ENTER para ir ao menu...')

while True:
    # Menu de Opções
    os.system('cls' if os.name == 'nt' else 'clear')
    print('\nDigite a opção que deseja...',
            '\n 1 - Adicionar Task',
            '\n 2 - Ver Tasks',
            '\n 3 - Remover todas as Tasks',
            '\n 4 - Executar Tasks (Round-Robin)',
            '\n 5 - Sair','\n')
    
    option = int(input("-> "))
    
    if option == 1:
        print('\nEspecifique os dados da nova Task...')
        ingress = int(input("Ingresso: "))
        duration = int(input("Duração: "))
        priority = int(input("Prioridade: "))
        
        # Criar a task
        task = {
            "id": (len(tasks)),
            "ingress": ingress,
            "duration": duration,
            "priority": priority
        }
        
        # Adicionar linha à tabela
        table.add_row(['Task {}'.format(len(tasks) + 1)])

        # Adicionar task à lista
        tasks.append(task)

    elif option == 2:
        id = 0
        for task in tasks:
            id += 1
            json_task = json.dumps(task)
            print("___________________________________________________________")
            print('< Task {} > '.format(str(id)) + json_task)
        
        print('__________________________________')
        input('Pressione ENTER para ir ao menu...')
    
    elif option == 3:
        # Remover todas as tasks
        table = PrettyTable([' '])
        tasks = []
        print('\nTasks removidas com sucesso!')
        time.sleep(2)

    elif option == 4:
        # Executar o Round Robin
        round_robin()

    elif option == 5:
        break
'''
        # Converter lista de tasks em JSON
        json_tasks = json.dumps(tasks)

        # Exibir o JSON resultante
        print(json_tasks)
'''
