#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init_task.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/time.h>
#define for_each_process(p) \
    for (p = &init_task ; (p = next_task(p)) != &init_task ; )
#define task_pid_nr(tsk) ((tsk)->pid)

asmlinkage long sys_call(void){
    int count=0,count2=0,count4=0;
    struct task_struct *p;
    long int get_time;
    struct timeval tv;
    for_each_process(p){
        if((p->state)==0){
            printk("%s\t[%d]\tRunnable %lu %llu %llu %llu\n",p->comm,task_pid_nr(p),(p->sched_info).pcount,(p->sched_info).run_delay,(p->sched_info).last_arrival,(p->sched_info).last_queued);
            count++;
        }
        
        else if(p->state ==1){
            printk("%s\t[%d]\tsleeping %lu %llu %llu %llu\n",p->comm,task_pid_nr(p),(p->sched_info).pcount,(p->sched_info).run_delay,(p->sched_info).last_arrival,(p->sched_info).last_queued);
            count2++;
        }
        
        count4++;
    }
    do_gettimeofday(&tv);
    get_time = tv.tv_sec;
    printk("Total no.of Process = %d\n",count4);
    printk("Total no.of Running(Runnable) process = %d\n",count);
    printk("Total no.of Sleeping(Runnable) process = %d\n",count2);
    //printk("Total no.of Blocked process = %d\n",count1);
    //printk("Total no.of Terminated process = %d\n",count3);
    printk("Time: %ld\n",get_time);
    return 0;
}
