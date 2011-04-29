/*
 * arch/arm/plat-omap/include/mach/nand.h
 *
 * Copyright (C) 2006 Micron Technology Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/mtd/partitions.h>

struct omap_nand_platform_data {
	unsigned int		options;
	int			cs;
	int			gpio_irq;
	struct mtd_partition	*parts;
	int			nr_parts;
	int			(*nand_setup)(void __iomem *);
	int			(*dev_ready)(struct omap_nand_platform_data *);
	int			dma_channel;
	int			gpmc_irq;
	void __iomem		*gpmc_cs_baseaddr;
	void __iomem		*gpmc_baseaddr;
	int			devsize;
	int			ecc_opt;/* 0x0 - sw ecc
					 * 0x1 - hw ecc default ecc layout
					 * 0x2 - hw ecc in romcode layout
					 */
};

/* size (4 KiB) for IO mapping */
#define NAND_IO_SIZE    SZ_4K

extern int gpmc_nand_init(struct omap_nand_platform_data *d);
