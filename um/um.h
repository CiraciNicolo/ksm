/*
 * User mode definitions for IOCTL codes, and such.
 * Stuff that are shared between both usermode and the kernel.
 */
#ifndef __UM_H
#define __UM_H

#ifdef __linux__
#include <linux/ioctl.h>
#include <linux/kdev_t.h>

#define UM_DEVICE_NAME		"ksm"
#define UM_DEVICE_PATH		"/dev/" UM_DEVICE_NAME

#define KSM_DEVICE_MAGIC	'K'
#define KSM_IOCTL_SANDBOX	_IOW(KSM_DEVICE_MAGIC, 0, int)
#define KSM_IOCTL_UNBOX		_IOW(KSM_DEVICE_MAGIC, 1, int)
#define KSM_IOCTL_SUBVERT	_IO(KSM_DEVICE_MAGIC, 2)
#define KSM_IOCTL_UNSUBVERT	_IO(KSM_DEVICE_MAGIC, 3)
#define KSM_IOCTL_INTRO_START	_IO(KSM_DEVICE_MAGIC, 4)
#define KSM_IOCTL_INTRO_STOP	_IO(KSM_DEVICE_MAGIC, 5)
#define KSM_IOCTL_INTRO_WATCH	_IOW(KSM_DEVICE_MAGIC, 6, int)
#define KSM_IOCTL_INTRO_UNWATCH	_IOW(KSM_DEVICE_MAGIC, 7, int)
#else
#define UM_DEVICE_NAME		L"ksm"
#define UM_DEVICE_PATH		L"\\\\.\\" UM_DEVICE_NAME

#define KSM_DEVICE_NAME		L"\\Device\\" UM_DEVICE_NAME
#define KSM_DOS_NAME		L"\\DosDevices\\" UM_DEVICE_NAME

#define KSM_DEVICE_MAGIC	0x00008008
#define KSM_IOCTL_SANDBOX	(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x800, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define KSM_IOCTL_UNBOX		(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x801, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define KSM_IOCTL_SUBVERT	(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x802, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define KSM_IOCTL_UNSUBVERT	(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x803, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define KSM_IOCTL_INTRO_START	(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x804, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define KSM_IOCTL_INTRO_STOP	(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x805, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define KSM_IOCTL_INTRO_WATCH	(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x806, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define KSM_IOCTL_INTRO_UNWATCH	(ULONG)CTL_CODE(KSM_DEVICE_MAGIC, 0x807, \
						METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#endif

#ifndef __linux__
#include <pshpack1.h>
#endif
struct watch_ioctl {
	unsigned long long addr;
	unsigned short access;
} __packed;
#ifndef __linux__
#include <poppack.h>
#endif

#endif
