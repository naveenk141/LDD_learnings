#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#define DNAME "simple_driver"
static int major;

int Example_open (struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT" hello from %s\n",__func__);
	return 0;
}

ssize_t Example_read (struct file *pfile, char __user *buff, size_t length, loff_t *offset){
	printk(KERN_ALERT" hello from %s\n",__func__);
	return 10;
}

ssize_t Example_write (struct file *pfile, const char __user *buff, size_t length, loff_t *offset){
	printk(KERN_ALERT" hello from %s\n",__func__);
	printk("%s\n",buff);
	return length;
}

int Example_release (struct inode *pinode, struct file *pfile){
        printk(KERN_ALERT" hello from %s\n",__func__);
        return 0;
}


struct file_operations fops ={
	.open= Example_open,
	.read= Example_read,
	.write= Example_write,
	.release= Example_release
};


static int hello_init(void) {
	printk(KERN_ALERT "hello from %s\n",__func__);
        major = register_chrdev(0,DNAME,&fops);
	printk("major no: %d\n",major);
	return 0;
}


static void hello_exit(void) {
	printk(KERN_ALERT "bye kaka from %s\n",__func__);
	unregister_chrdev(major,DNAME);

}


module_init(hello_init);
module_exit(hello_exit);


MODULE_AUTHOR("NAVEEN");
MODULE_DESCRIPTION("Example");
MODULE_LICENSE("GPL");



