#include <linux/init.h>
#include <linux/module.h>

/* Module parameter usage:
 * insmod hello.ko count=10 textparam="newbie"
 *
 * module_param(name,type,perm)
 * Permissions define how module appears in sysfs. 0 equals no appearance.
 * /sys/module/hello and /sys/module/hello/parameters
 * S_IRUGO permission is world-readable, not changeable (0444)
 * S_I = ?, Read User Group Other
 * see linux/stat.h for more info
 */

static char *textparam = "world";
static int count = 1;
module_param(count, int, S_IRUGO);
module_param(textparam, charp, S_IRUGO);

/* The __init token tells the kernel that the function is used only upon
 * initialization. The functions is dropped after the module is loaded.
 * This is where race conditions might occur.
 */
 
static int __init hello_init(void)
{
	int i;
	for (i = 0; i < count; ++i)
	{
		printk(KERN_ALERT "Hello, %s!\n", textparam);
	}
	return 0;
}

/* The __exit token marks code for module unload only, and is compiled into
 * a special ELF section. If the module is build directly into kernel and 
 * the kernel disallows module unloading, the function is discarded.
 */

static void __exit hello_cleanup(void)
{
	printk(KERN_ALERT "Goodbye.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("tqre");
MODULE_DESCRIPTION("'Hello,world!' -kernel module with parameters");
MODULE_VERSION("0.1");
