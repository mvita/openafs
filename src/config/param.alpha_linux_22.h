#ifndef _PARAM_ALPHA_LINUX2216_22_H_
#define _PARAM_ALPHA_LINUX2216_22_H_

/* Linux 2.2.16 kernel on Alpha with glibc 2.2 */
 
/* In user space the AFS_LINUX20_ENV should be sufficient. In the kernel,
 * it's a judgment call. If something is obviously sparc64 specific, use that
 * #define instead. Note that "20" refers to the linux 2.0 kernel. The "2"
 * in the sysname is the current version of the client. This takes into
 * account the perferred OS user space configuration as well as the kernel.
 */

#define AFS_LINUX20_ENV        1
#define AFS_LINUX22_ENV        1
#define AFS_ALPHA_LINUX20_ENV  1
#define AFS_ALPHA_LINUX22_ENV  1
#define __alpha        1
#define AFS_LINUX_64BIT_KERNEL 1
#define AFS_NONFSTRANS 1

#define AFS_MOUNT_AFS "afs"    /* The name of the filesystem type. */
#define AFS_SYSCALL 338
#define AFS_64BIT_IOPS_ENV  1
#define AFS_NAMEI_ENV     1   /* User space interface to file system */

#define AFS_64BIT_ENV          1       /* Defines afs_int32 as int, not long. */
#define AFS_64BITPOINTER_ENV   1       /* pointers are 64 bits. */

#if defined(__KERNEL__) && !defined(KDUMP_KERNEL)
#include <linux/config.h>
#ifdef CONFIG_SMP
#undef CONFIG_SMP
#endif
/* Using "AFS_SMP" to map to however many #define's are required to get
 * MP to compile for Linux
 */
#ifdef AFS_SMP
#define CONFIG_SMP 1
#ifndef __SMP__
#define __SMP__
#endif
#define AFS_GLOBAL_SUNLOCK
#endif
#if defined(MODULE) && defined(CONFIG_MODVERSIONS)
#define MODVERSIONS
#include <linux/modversions.h>
#endif
#endif /* __KERNEL__  && !DUMP_KERNEL*/

#include <afs/afs_sysnames.h>

#define AFS_USERSPACE_IP_ADDR 1
#define RXK_LISTENER_ENV 1
#define AFS_GCPAGS             0       /* if nonzero, garbage collect PAGs */

/* Machine / Operating system information */
#define SYS_NAME       "alpha_linux_22"
#define SYS_NAME_ID    SYS_NAME_ID_alpha_linux_22
#define AFSLITTLE_ENDIAN    1
#define AFS_HAVE_FFS        1       /* Use system's ffs. */
#define AFS_HAVE_STATVFS    0  /* System doesn't support statvfs */
#define AFS_VM_RDWR_ENV            1   /* read/write implemented via VM */

#ifdef KERNEL
#ifndef MIN
#define MIN(A,B) ((A) < (B) ? (A) : (B))
#endif
#ifndef MAX
#define MAX(A,B) ((A) > (B) ? (A) : (B))
#endif
#endif /* KERNEL */

#endif /* _PARAM_ALPHA_LINUX2216_22_H_ */
