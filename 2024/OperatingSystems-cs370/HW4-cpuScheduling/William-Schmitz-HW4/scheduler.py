import csv
import argparse
import copy


class Process:
    def __init__(self, pid, arrival_time, burst_time, priority):
        self.pid = pid
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.remaining_time = burst_time
        self.completion_time = 0
        self.waiting_time = 0
        self.turnaround_time = 0


    def execute(self, time):
        if self.remaining_time <= 0:
            self.completion_time = time
            self.turnaround_time = self.completion_time - self.arrival_time
            self.waiting_time = self.turnaround_time - self.burst_time
            return True
        else:
            self.remaining_time -= 1
            return False


def create_processes_from_file(file_path: str) -> list:
    all_processes: list[Process] = []
    with open(file_path, mode='r') as file:
        csv_reader = csv.reader(file)
        next(csv_reader)
        for row in csv_reader:
            all_processes.append(Process(int(row[0]), int(row[1]), int(row[2]), int(row[3])))
    return all_processes

    
def display_results(title, processes, gantt_chart, gantt_title):
    print(f"{title}\n")
    print("Process ID | Waiting Time | Turnaround Time\n")
    processes_by_pid = sorted(processes, key=lambda process: process.pid)
    average_waiting_time = 0
    average_turnaround_time = 0
    for each in processes_by_pid:
        average_waiting_time += each.waiting_time
        average_turnaround_time += each.turnaround_time
        print(f"     {each.pid}     |       {each.waiting_time}      |         {each.turnaround_time}")
    print("\n")
    print(f"{gantt_title}")
    print("\n")
    start_time = 0
    last_pid = gantt_chart[start_time]
    for time, pid in enumerate(gantt_chart):
        if pid != last_pid:
            print(f"[{start_time}]--{last_pid}--[{time}]")
            start_time = time
        last_pid = pid
    
    print(f"[{start_time}]--{last_pid}--[{len(gantt_chart)}]")
    print("\n")
    print(f"Average Waiting Time: {average_waiting_time/len(processes)}")
    print(f"Average Turnaround Time: {average_turnaround_time/len(processes)}")
    print(f"Throughput: {len(processes)/len(gantt_chart)}")
    print("\n")


def first_come_first_serve(processes):
    gantt_chart = []
    time = 0
    ready_processes = sorted(processes, key=lambda process: (process.arrival_time, process.pid))
    while ready_processes:
        is_stopped = False
        if ready_processes[0].arrival_time <= time:
            if ready_processes[0].execute(time):
                ready_processes.pop(0)
                is_stopped = True
            else:
                gantt_chart.append(ready_processes[0].pid)
        else:
            gantt_chart.append("IDLE")
        if not is_stopped:
            time += 1
    
    display_results("___________________FCFS____________________", processes, gantt_chart, "_____________FCFS Gantt Chart______________")


def priority_preemption(processes):
    gantt_chart = []
    ready_processes = processes.copy()
    time = 0

    while ready_processes:
        is_stopped = False
        highest_priority_process = None
        highest_priority = 10_000
        
        if highest_priority_process is not None:
            highest_priority = highest_priority_process.priority

        for each in ready_processes:
            if each.priority < highest_priority and each.arrival_time <= time:
                highest_priority_process = each
                highest_priority = each.priority
        
        # Check for highest priority
        if highest_priority_process is not None:
            if highest_priority_process.execute(time):
                ready_processes.pop(ready_processes.index(highest_priority_process))
                is_stopped = True
            else:
                gantt_chart.append(highest_priority_process.pid)
        else:
            gantt_chart.append("IDLE")

        if not is_stopped:
            time += 1

    display_results("________________Priority with Preemption________________", processes, gantt_chart, "__________Priority with Preemption Gantt Chart___________")


def round_robin_scheduling(processes, quantum):
    gantt_chart = []
    time = 0
    step = 0
    processes_finished = 0
    processes = sorted(processes, key=lambda p: (p.arrival_time, p.pid))

    while processes_finished < len(processes):
        is_idle = True
        
        for _i in range(0, len(processes)):
            current_process = processes[step]
            
            # stepping over processes if they have not arrived in time, or are completed
            if current_process.arrival_time <= time and current_process.remaining_time > 0:
                is_idle = False
                
                # There are cases where the remaining time is less than the given quantum
                execution_time = min(quantum, current_process.remaining_time)
                current_process.remaining_time -= execution_time
                time += execution_time  # time incremented!
                
                for _j in range(0, execution_time):
                    gantt_chart.append(current_process.pid)
                
                if current_process.remaining_time == 0:
                    # Process has completed
                    current_process.completion_time = time
                    current_process.turnaround_time = current_process.completion_time - current_process.arrival_time
                    current_process.waiting_time = current_process.turnaround_time - current_process.burst_time
                    processes_finished += 1
                step = (step + 1) % len(processes)
                break
            step = (step + 1) % len(processes)

        if is_idle:
            gantt_chart.append("IDLE")
            time += 1  # time incremented!
    display_results("___________Round Robin___________", processes, gantt_chart, "___________Round Robin Gantt Chart___________")


def main():
    parser = argparse.ArgumentParser(description="Process some arguments.")
    parser.add_argument("arg1", help="First argument")
    parser.add_argument("arg2", help="Second argument")
    args = parser.parse_args()

    file_path = args.arg1
    quantum = args.arg2

    processes = create_processes_from_file(file_path)
    first_come_first_serve(copy.deepcopy(processes))
    priority_preemption(copy.deepcopy(processes))
    round_robin_scheduling(copy.deepcopy(processes), int(quantum))


if __name__ == "__main__":
    main()