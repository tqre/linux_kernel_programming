#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

/* A reference to current process added with <linux/sched.h>.
 * Module parameter usage:
 * insmod hello.ko count=10 textparam="newbie"
 */

static char *textparam = "world";
static int count = 1;
module_param(count, int, S_IRUGO);
module_param(textparam, charp, S_IRUGO);

static int __init hello_init(void)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		printk(KERN_ALERT "Hello, %s!\n", textparam);
	}
	printk(KERN_ALERT "The process is \"%s\" (pid %i)\n",
		current->comm, current->pid);

/* C arrow operator: foo->bar is equivalent to (*foo).bar
 * Here, 'current' is a pointer, and we are accessing .comm (command name)
 * or .pid of the process.
 */

	return 0;
}

static void __exit hello_cleanup(void)
{
	printk(KERN_ALERT "Process \"%s\" (pid %i) exiting.\n",
		current->comm, current->pid);
	printk(KERN_ALERT "Goodbye.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("tqre");
MODULE_DESCRIPTION("HelloWorld module, parameters and process identifier.");
MODULE_VERSION("0.2");
