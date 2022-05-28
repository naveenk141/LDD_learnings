#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>


int device_open(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Hello from %s\n",__func__);
	return 0;
}

ssize_t device_read(struct file *pfile,char __user *buffer,size_t length,loff_t *offset){
	printk(KERN_ALERT "Hello from %s\n",__func__);
	return 0;
}

ssize_t device_write(struct file *pfile,const char __user *buffer,size_t length,loff_t *offset){
	printk(KERN_ALERT "Hello from %s\n",__func__);
	return length;
}

int device_release(struct inode *pinode, struct file *pfile){
	printk(KERN_ALERT "Hello from %s\n",__func__);
	return 0;
} 

struct file_operations fops = {
	.read = device_read, 
	.write = device_write,
	.open = device_open,  
	.release = device_release
};

static int hello_init(void){
	printk(KERN_ALERT "Hello World! from %s\n",__func__);
	register_chrdev(240,"Example_device",&fops);
	return 0;
}

static void hello_exit(void){
	printk(KERN_ALERT "Good Bye World! from %s\n",__func__);
	unregister_chrdev(240,"Example_device");
}


module_init(hello_init);
module_exit(hello_exit);



MODULE_AUTHOR("Naveen");
MODULE_DESCRIPTION("Example program.");
MODULE_LICENSE("GPL");
MODULE_VERSION("6");
