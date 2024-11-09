class Process:
    def __init__(self, pid, arrival_time, burst_time, priority=0):
        self.pid = pid
        self.arrival_time = arrival_time
        self.burst_time = burst_time
        self.priority = priority
        self.remaining_time = burst_time
        self.completion_time = 0
        self.waiting_time = 0
        self.turnaround_time = 0
        self.start_time = None

def round_robin_scheduling(processes, time_quantum):
    time = 0
    queue = []
    gantt_chart = []
    average_waiting_time = 0
    average_turnaround_time = 0

    # Sort processes by arrival time initially
    processes.sort(key=lambda p: (p.arrival_time, p.pid))
    n = len(processes)

    # Load processes that arrive at time 0 into the queue
    for process in processes:
        if process.arrival_time == time:
            queue.append(process)

    # Main Round Robin scheduling loop
    while queue or any(p.remaining_time > 0 for p in processes):
        if queue:
            current_process = queue.pop(0)

            # Execute the process for either the time quantum or the remaining time, whichever is smaller
            if current_process.remaining_time <= time_quantum:
                execution_time = current_process.remaining_time
                time += execution_time
                current_process.remaining_time = 0
                current_process.completion_time = time

                # Record in Gantt chart
                gantt_chart.append(f"[{time - execution_time}]--{current_process.pid}--[{time}]")

                # Calculate waiting time and turnaround time
                current_process.turnaround_time = current_process.completion_time - current_process.arrival_time
                current_process.waiting_time = current_process.turnaround_time - current_process.burst_time

            else:
                # Process partially executed
                execution_time = time_quantum
                time += execution_time
                current_process.remaining_time -= execution_time

                # Record in Gantt chart
                gantt_chart.append(f"[{time - execution_time}]--{current_process.pid}--[{time}]")

                # Re-add to queue if it still has remaining time
                for process in processes:
                    if process.arrival_time <= time and process not in queue and process.remaining_time > 0:
                        queue.append(process)

                queue.append(current_process)

            # Load any newly arrived processes
            for process in processes:
                if process.arrival_time > time - execution_time and process.arrival_time <= time and process not in queue and process.remaining_time > 0:
                    queue.insert(0, process)

        else:
            # No processes in the queue, move time forward to the next process arrival
            idle_time = min(p.arrival_time for p in processes if p.remaining_time > 0) - time
            time += idle_time
            gantt_chart.append(f"[{time - idle_time}]--IDLE--[{time}]")
            for process in processes:
                if process.arrival_time <= time and process.remaining_time > 0:
                    queue.append(process)

    # Calculate average waiting time, average turnaround time, and throughput
    total_waiting_time = sum(p.waiting_time for p in processes)
    total_turnaround_time = sum(p.turnaround_time for p in processes)
    average_waiting_time = total_waiting_time / n
    average_turnaround_time = total_turnaround_time / n
    throughput = n / time

    # Print the results
    print("Round Robin")
    print("Process ID | Waiting Time | Turnaround Time")
    for p in processes:
        print(f"{p.pid} | {p.waiting_time} | {p.turnaround_time}")
    
    print("Round Robin Gantt Chart")
    print(" ".join(gantt_chart))
    print(f"Average Waiting Time: {average_waiting_time}")
    print(f"Average Turnaround Time: {average_turnaround_time}")
    print(f"Throughput: {throughput}")

# Example Usage:
processes = [
    Process(3, 0, 6, 1),
    Process(2, 0, 5, 3),
    Process(1, 12, 8, 4),
    Process(4, 13, 6, 2)
]
time_quantum = 3
round_robin_scheduling(processes, time_quantum)
