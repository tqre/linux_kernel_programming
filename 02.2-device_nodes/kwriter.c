/* A char device module which writes it's input into dmesg. A user-space
 * program is also supplied.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>

dev_t devno;

/* Need to declare function prototypes for kwr_fops */


/* File operations on the driver are defined in the following struct. These
 * implement system calls to the driver. The device file can be thought as
 * an object as in OOP, and operations here are the methods. See <linux/fs.h>.
 */

struct file_operations kwr_fops = {
	.owner =	THIS_MODULE,	// A macro, used every time?
	.read =		kwr_read,
	.write =	kwr_write,
	.open =		kwr_open,
	.release =	kwr_release,
};

static int __init kwr_init(void)
{
	int ret;
	ret = alloc_chrdev_region(&devno, 0, 1, "kwriter");
	printk(KERN_INFO
	"Allocated %i.%i", MAJOR(devno), MINOR(devno) "for K-writer");

	return 0;
}

static void __exit kwr_cleanup(void)
{
	unregister_chrdev_region(devno, 1);
}

module_init(kwr_init);
module_exit(kwr_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("tqre");
MODULE_DESCRIPTION("Char device exercise");
MODULE_VERSION("0.1");

