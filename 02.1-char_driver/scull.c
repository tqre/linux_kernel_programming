#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

/* Linux kernel coding exercise, loadable char device module.
 * First step: Allocating dynamically and releasing device MAJ.MIN numbers. 
 * It can be seen now in /proc/devices
 */

dev_t devno;
static int devmaj, devmin, ret;

static int __init scull_init(void)
{
	ret = alloc_chrdev_region(&devno, 0, 1, "scull");
	
	// These macros get the device number
	devmaj = MAJOR(devno);
	devmin = MINOR(devno);
	printk(KERN_ALERT "Allocated %i.%i", devmaj, devmin);

	return 0;
}

static void __exit scull_cleanup(void)
{
	printk(KERN_ALERT "Unregistering %i.%i", devmaj, devmin);
	unregister_chrdev_region(devno, 1);
}

module_init(scull_init);
module_exit(scull_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("tqre");
MODULE_DESCRIPTION("Simple Character Utility for Loading Localities");
MODULE_VERSION("0.1");

