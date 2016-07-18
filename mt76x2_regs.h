/*
 * Copyright (C) 2016 Felix Fietkau <nbd@openwrt.org>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef __MT76x2_REGS_H
#define __MT76x2_REGS_H

#define MT_ASIC_VERSION			0x0000

#define MT76XX_REV_E3		0x22
#define MT76XX_REV_E4		0x33

#define MT_CMB_CTRL			0x0020
#define MT_CMB_CTRL_XTAL_RDY		BIT(22)
#define MT_CMB_CTRL_PLL_LD		BIT(23)

#define MT_EFUSE_CTRL			0x0024
#define MT_EFUSE_CTRL_AOUT		GENMASK(5, 0)
#define MT_EFUSE_CTRL_MODE		GENMASK(7, 6)
#define MT_EFUSE_CTRL_LDO_OFF_TIME	GENMASK(13, 8)
#define MT_EFUSE_CTRL_LDO_ON_TIME	GENMASK(15, 14)
#define MT_EFUSE_CTRL_AIN		GENMASK(25, 16)
#define MT_EFUSE_CTRL_KICK		BIT(30)
#define MT_EFUSE_CTRL_SEL		BIT(31)

#define MT_EFUSE_DATA_BASE		0x0028
#define MT_EFUSE_DATA(_n)		(MT_EFUSE_DATA_BASE + ((_n) << 2))

#define MT_COEXCFG0			0x0040
#define MT_COEXCFG0_COEX_EN		BIT(0)

#define MT_WLAN_FUN_CTRL		0x0080
#define MT_WLAN_FUN_CTRL_WLAN_EN	BIT(0)
#define MT_WLAN_FUN_CTRL_WLAN_CLK_EN	BIT(1)
#define MT_WLAN_FUN_CTRL_WLAN_RESET_RF	BIT(2)

#define MT_WLAN_FUN_CTRL_WLAN_RESET	BIT(3) /* MT76x0 */
#define MT_WLAN_FUN_CTRL_CSR_F20M_CKEN	BIT(3) /* MT76x2 */

#define MT_WLAN_FUN_CTRL_PCIE_CLK_REQ	BIT(4)
#define MT_WLAN_FUN_CTRL_FRC_WL_ANT_SEL	BIT(5)
#define MT_WLAN_FUN_CTRL_INV_ANT_SEL	BIT(6)
#define MT_WLAN_FUN_CTRL_WAKE_HOST	BIT(7)

#define MT_WLAN_FUN_CTRL_THERM_RST	BIT(8) /* MT76x2 */
#define MT_WLAN_FUN_CTRL_THERM_CKEN	BIT(9) /* MT76x2 */

#define MT_WLAN_FUN_CTRL_GPIO_IN	GENMASK(15, 8) /* MT76x0 */
#define MT_WLAN_FUN_CTRL_GPIO_OUT	GENMASK(23, 16) /* MT76x0 */
#define MT_WLAN_FUN_CTRL_GPIO_OUT_EN	GENMASK(31, 24) /* MT76x0 */

#define MT_XO_CTRL0			0x0100
#define MT_XO_CTRL1			0x0104
#define MT_XO_CTRL2			0x0108
#define MT_XO_CTRL3			0x010c
#define MT_XO_CTRL4			0x0110

#define MT_XO_CTRL5			0x0114
#define MT_XO_CTRL5_C2_VAL		GENMASK(14, 8)

#define MT_XO_CTRL6			0x0118
#define MT_XO_CTRL6_C2_CTRL		GENMASK(14, 8)

#define MT_XO_CTRL7			0x011c

#define MT_WLAN_MTC_CTRL		0x10148
#define MT_WLAN_MTC_CTRL_MTCMOS_PWR_UP	BIT(0)
#define MT_WLAN_MTC_CTRL_PWR_ACK	BIT(12)
#define MT_WLAN_MTC_CTRL_PWR_ACK_S	BIT(13)
#define MT_WLAN_MTC_CTRL_BBP_MEM_PD	GENMASK(19, 16)
#define MT_WLAN_MTC_CTRL_PBF_MEM_PD	BIT(20)
#define MT_WLAN_MTC_CTRL_FCE_MEM_PD	BIT(21)
#define MT_WLAN_MTC_CTRL_TSO_MEM_PD	BIT(22)
#define MT_WLAN_MTC_CTRL_BBP_MEM_RB	BIT(24)
#define MT_WLAN_MTC_CTRL_PBF_MEM_RB	BIT(25)
#define MT_WLAN_MTC_CTRL_FCE_MEM_RB	BIT(26)
#define MT_WLAN_MTC_CTRL_TSO_MEM_RB	BIT(27)
#define MT_WLAN_MTC_CTRL_STATE_UP	BIT(28)

#define MT_INT_SOURCE_CSR		0x0200
#define MT_INT_MASK_CSR			0x0204

#define MT_INT_RX_DONE(_n)		BIT(_n)
#define MT_INT_RX_DONE_ALL		GENMASK(1, 0)
#define MT_INT_TX_DONE_ALL		GENMASK(13, 4)
#define MT_INT_TX_DONE(_n)		BIT(_n + 4)
#define MT_INT_RX_COHERENT		BIT(16)
#define MT_INT_TX_COHERENT		BIT(17)
#define MT_INT_ANY_COHERENT		BIT(18)
#define MT_INT_MCU_CMD			BIT(19)
#define MT_INT_TBTT			BIT(20)
#define MT_INT_PRE_TBTT			BIT(21)
#define MT_INT_TX_STAT			BIT(22)
#define MT_INT_AUTO_WAKEUP		BIT(23)
#define MT_INT_GPTIMER			BIT(24)
#define MT_INT_RXDELAYINT		BIT(26)
#define MT_INT_TXDELAYINT		BIT(27)

#define MT_WPDMA_GLO_CFG		0x0208
#define MT_WPDMA_GLO_CFG_TX_DMA_EN	BIT(0)
#define MT_WPDMA_GLO_CFG_TX_DMA_BUSY	BIT(1)
#define MT_WPDMA_GLO_CFG_RX_DMA_EN	BIT(2)
#define MT_WPDMA_GLO_CFG_RX_DMA_BUSY	BIT(3)
#define MT_WPDMA_GLO_CFG_DMA_BURST_SIZE	GENMASK(5, 4)
#define MT_WPDMA_GLO_CFG_TX_WRITEBACK_DONE	BIT(6)
#define MT_WPDMA_GLO_CFG_BIG_ENDIAN	BIT(7)
#define MT_WPDMA_GLO_CFG_HDR_SEG_LEN	GENMASK(15, 8)
#define MT_WPDMA_GLO_CFG_CLK_GATE_DIS	BIT(30)
#define MT_WPDMA_GLO_CFG_RX_2B_OFFSET	BIT(31)

#define MT_WPDMA_RST_IDX		0x020c

#define MT_WPDMA_DELAY_INT_CFG		0x0210

#define MT_WMM_AIFSN		0x0214
#define MT_WMM_AIFSN_MASK		GENMASK(3, 0)
#define MT_WMM_AIFSN_SHIFT(_n)		((_n) * 4)

#define MT_WMM_CWMIN		0x0218
#define MT_WMM_CWMIN_MASK		GENMASK(3, 0)
#define MT_WMM_CWMIN_SHIFT(_n)		((_n) * 4)

#define MT_WMM_CWMAX		0x021c
#define MT_WMM_CWMAX_MASK		GENMASK(3, 0)
#define MT_WMM_CWMAX_SHIFT(_n)		((_n) * 4)

#define MT_WMM_TXOP_BASE		0x0220
#define MT_WMM_TXOP(_n)			(MT_WMM_TXOP_BASE + (((_n) / 2) << 2))
#define MT_WMM_TXOP_SHIFT(_n)		((_n & 1) * 16)
#define MT_WMM_TXOP_MASK		GENMASK(15, 0)

#define MT_TSO_CTRL			0x0250
#define MT_HEADER_TRANS_CTRL_REG	0x0260

#define MT_TX_RING_BASE			0x0300
#define MT_RX_RING_BASE			0x03c0

#define MT_TX_HW_QUEUE_MCU		8
#define MT_TX_HW_QUEUE_MGMT		9

#define MT_PBF_SYS_CTRL			0x0400
#define MT_PBF_SYS_CTRL_MCU_RESET	BIT(0)
#define MT_PBF_SYS_CTRL_DMA_RESET	BIT(1)
#define MT_PBF_SYS_CTRL_MAC_RESET	BIT(2)
#define MT_PBF_SYS_CTRL_PBF_RESET	BIT(3)
#define MT_PBF_SYS_CTRL_ASY_RESET	BIT(4)

#define MT_PBF_CFG			0x0404
#define MT_PBF_CFG_TX0Q_EN		BIT(0)
#define MT_PBF_CFG_TX1Q_EN		BIT(1)
#define MT_PBF_CFG_TX2Q_EN		BIT(2)
#define MT_PBF_CFG_TX3Q_EN		BIT(3)
#define MT_PBF_CFG_RX0Q_EN		BIT(4)
#define MT_PBF_CFG_RX_DROP_EN		BIT(8)

#define MT_PBF_TX_MAX_PCNT		0x0408
#define MT_PBF_RX_MAX_PCNT		0x040c

#define MT_BCN_OFFSET_BASE		0x041c
#define MT_BCN_OFFSET(_n)		(MT_BCN_OFFSET_BASE + ((_n) << 2))

#define MT_RF_BYPASS_0			0x0504
#define MT_RF_BYPASS_1			0x0508
#define MT_RF_SETTING_0			0x050c

#define MT_RF_DATA_WRITE		0x0524

#define MT_RF_CTRL			0x0528
#define MT_RF_CTRL_ADDR			GENMASK(11, 0)
#define MT_RF_CTRL_WRITE		BIT(12)
#define MT_RF_CTRL_BUSY			BIT(13)
#define MT_RF_CTRL_IDX			BIT(16)

#define MT_RF_DATA_READ			0x052c

#define MT_FCE_PSE_CTRL			0x0800
#define MT_FCE_PARAMETERS		0x0804
#define MT_FCE_CSO			0x0808

#define MT_FCE_L2_STUFF			0x080c
#define MT_FCE_L2_STUFF_HT_L2_EN	BIT(0)
#define MT_FCE_L2_STUFF_QOS_L2_EN	BIT(1)
#define MT_FCE_L2_STUFF_RX_STUFF_EN	BIT(2)
#define MT_FCE_L2_STUFF_TX_STUFF_EN	BIT(3)
#define MT_FCE_L2_STUFF_WR_MPDU_LEN_EN	BIT(4)
#define MT_FCE_L2_STUFF_MVINV_BSWAP	BIT(5)
#define MT_FCE_L2_STUFF_TS_CMD_QSEL_EN	GENMASK(15, 8)
#define MT_FCE_L2_STUFF_TS_LEN_EN	GENMASK(23, 16)
#define MT_FCE_L2_STUFF_OTHER_PORT	GENMASK(25, 24)

#define MT_FCE_WLAN_FLOW_CONTROL1	0x0824

#define MT_PAUSE_ENABLE_CONTROL1	0x0a38

#define MT_MAC_CSR0			0x1000

#define MT_MAC_SYS_CTRL			0x1004
#define MT_MAC_SYS_CTRL_RESET_CSR	BIT(0)
#define MT_MAC_SYS_CTRL_RESET_BBP	BIT(1)
#define MT_MAC_SYS_CTRL_ENABLE_TX	BIT(2)
#define MT_MAC_SYS_CTRL_ENABLE_RX	BIT(3)

#define MT_MAC_ADDR_DW0			0x1008
#define MT_MAC_ADDR_DW1			0x100c

#define MT_MAC_BSSID_DW0		0x1010
#define MT_MAC_BSSID_DW1		0x1014
#define MT_MAC_BSSID_DW1_ADDR		GENMASK(15, 0)
#define MT_MAC_BSSID_DW1_MBSS_MODE	GENMASK(17, 16)
#define MT_MAC_BSSID_DW1_MBEACON_N	GENMASK(20, 18)
#define MT_MAC_BSSID_DW1_MBSS_LOCAL_BIT	BIT(21)
#define MT_MAC_BSSID_DW1_MBSS_MODE_B2	BIT(22)
#define MT_MAC_BSSID_DW1_MBEACON_N_B3	BIT(23)
#define MT_MAC_BSSID_DW1_MBSS_IDX_BYTE	GENMASK(26, 24)

#define MT_MAX_LEN_CFG			0x1018

#define MT_AMPDU_MAX_LEN_20M1S		0x1030
#define MT_AMPDU_MAX_LEN_20M2S		0x1034
#define MT_AMPDU_MAX_LEN_40M1S		0x1038
#define MT_AMPDU_MAX_LEN_40M2S		0x103c
#define MT_AMPDU_MAX_LEN		0x1040

#define MT_WCID_DROP_BASE		0x106c
#define MT_WCID_DROP(_n)		(MT_WCID_DROP_BASE + ((_n) >> 5) * 4)
#define MT_WCID_DROP_MASK(_n)		BIT((_n) % 32)

#define MT_BCN_BYPASS_MASK		0x108c

#define MT_MAC_APC_BSSID_BASE		0x1090
#define MT_MAC_APC_BSSID_L(_n)		(MT_MAC_APC_BSSID_BASE + ((_n) * 8))
#define MT_MAC_APC_BSSID_H(_n)		(MT_MAC_APC_BSSID_BASE + ((_n) * 8 + 4))
#define MT_MAC_APC_BSSID_H_ADDR		GENMASK(15, 0)
#define MT_MAC_APC_BSSID0_H_EN		BIT(16)

#define MT_XIFS_TIME_CFG		0x1100
#define MT_XIFS_TIME_CFG_CCK_SIFS	GENMASK(7, 0)
#define MT_XIFS_TIME_CFG_OFDM_SIFS	GENMASK(15, 8)
#define MT_XIFS_TIME_CFG_OFDM_XIFS	GENMASK(19, 16)
#define MT_XIFS_TIME_CFG_EIFS		GENMASK(28, 20)
#define MT_XIFS_TIME_CFG_BB_RXEND_EN	BIT(29)

#define MT_BKOFF_SLOT_CFG		0x1104
#define MT_BKOFF_SLOT_CFG_SLOTTIME	GENMASK(7, 0)
#define MT_BKOFF_SLOT_CFG_CC_DELAY	GENMASK(11, 8)

#define MT_CH_TIME_CFG			0x110c
#define MT_CH_TIME_CFG_TIMER_EN		BIT(0)
#define MT_CH_TIME_CFG_TX_AS_BUSY	BIT(1)
#define MT_CH_TIME_CFG_RX_AS_BUSY	BIT(2)
#define MT_CH_TIME_CFG_NAV_AS_BUSY	BIT(3)
#define MT_CH_TIME_CFG_EIFS_AS_BUSY	BIT(4)
#define MT_CH_TIME_CFG_MDRDY_CNT_EN	BIT(5)
#define MT_CH_TIME_CFG_CH_TIMER_CLR	GENMASK(9, 8)
#define MT_CH_TIME_CFG_MDRDY_CLR	GENMASK(11, 10)

#define MT_BEACON_TIME_CFG		0x1114
#define MT_BEACON_TIME_CFG_INTVAL	GENMASK(15, 0)
#define MT_BEACON_TIME_CFG_TIMER_EN	BIT(16)
#define MT_BEACON_TIME_CFG_SYNC_MODE	GENMASK(18, 17)
#define MT_BEACON_TIME_CFG_TBTT_EN	BIT(19)
#define MT_BEACON_TIME_CFG_BEACON_TX	BIT(20)
#define MT_BEACON_TIME_CFG_TSF_COMP	GENMASK(31, 24)

#define MT_TBTT_SYNC_CFG		0x1118
#define MT_TBTT_TIMER_CFG		0x1124

#define MT_INT_TIMER_CFG		0x1128
#define MT_INT_TIMER_CFG_PRE_TBTT	GENMASK(15, 0)
#define MT_INT_TIMER_CFG_GP_TIMER	GENMASK(31, 16)

#define MT_INT_TIMER_EN			0x112c
#define MT_INT_TIMER_EN_PRE_TBTT_EN	BIT(0)
#define MT_INT_TIMER_EN_GP_TIMER_EN	BIT(1)

#define MT_CH_IDLE			0x1130
#define MT_CH_BUSY			0x1134
#define MT_EXT_CH_BUSY			0x1138
#define MT_ED_CCA_TIMER			0x1140

#define MT_MAC_STATUS			0x1200
#define MT_MAC_STATUS_TX		BIT(0)
#define MT_MAC_STATUS_RX		BIT(1)

#define MT_PWR_PIN_CFG			0x1204
#define MT_AUX_CLK_CFG			0x120c

#define MT_BB_PA_MODE_CFG0		0x1214
#define MT_BB_PA_MODE_CFG1		0x1218
#define MT_RF_PA_MODE_CFG0		0x121c
#define MT_RF_PA_MODE_CFG1		0x1220

#define MT_RF_PA_MODE_ADJ0		0x1228
#define MT_RF_PA_MODE_ADJ1		0x122c

#define MT_DACCLK_EN_DLY_CFG		0x1264

#define MT_EDCA_CFG_BASE		0x1300
#define MT_EDCA_CFG_AC(_n)		(MT_EDCA_CFG_BASE + ((_n) << 2))
#define MT_EDCA_CFG_TXOP		GENMASK(7, 0)
#define MT_EDCA_CFG_AIFSN		GENMASK(11, 8)
#define MT_EDCA_CFG_CWMIN		GENMASK(15, 12)
#define MT_EDCA_CFG_CWMAX		GENMASK(19, 16)

#define MT_TX_PWR_CFG_0			0x1314
#define MT_TX_PWR_CFG_1			0x1318
#define MT_TX_PWR_CFG_2			0x131c
#define MT_TX_PWR_CFG_3			0x1320
#define MT_TX_PWR_CFG_4			0x1324

#define MT_TX_BAND_CFG			0x132c
#define MT_TX_BAND_CFG_UPPER_40M	BIT(0)
#define MT_TX_BAND_CFG_5G		BIT(1)
#define MT_TX_BAND_CFG_2G		BIT(2)

#define MT_HT_FBK_TO_LEGACY		0x1384
#define MT_TX_MPDU_ADJ_INT		0x1388

#define MT_TX_PWR_CFG_7			0x13d4
#define MT_TX_PWR_CFG_8			0x13d8
#define MT_TX_PWR_CFG_9			0x13dc

#define MT_TX_SW_CFG0			0x1330
#define MT_TX_SW_CFG1			0x1334
#define MT_TX_SW_CFG2			0x1338

#define MT_TXOP_CTRL_CFG		0x1340

#define MT_TX_RTS_CFG			0x1344
#define MT_TX_RTS_CFG_RETRY_LIMIT	GENMASK(7, 0)
#define MT_TX_RTS_CFG_THRESH		GENMASK(23, 8)
#define MT_TX_RTS_FALLBACK		BIT(24)

#define MT_TX_TIMEOUT_CFG		0x1348
#define MT_TX_TIMEOUT_CFG_ACKTO		GENMASK(15, 8)

#define MT_TX_RETRY_CFG			0x134c
#define MT_VHT_HT_FBK_CFG1		0x1358

#define MT_PROT_CFG_RATE		GENMASK(15, 0)
#define MT_PROT_CFG_CTRL		GENMASK(17, 16)
#define MT_PROT_CFG_NAV			GENMASK(19, 18)
#define MT_PROT_CFG_TXOP_ALLOW		GENMASK(25, 20)
#define MT_PROT_CFG_RTS_THRESH		BIT(26)

#define MT_CCK_PROT_CFG			0x1364
#define MT_OFDM_PROT_CFG		0x1368
#define MT_MM20_PROT_CFG		0x136c
#define MT_MM40_PROT_CFG		0x1370
#define MT_GF20_PROT_CFG		0x1374
#define MT_GF40_PROT_CFG		0x1378

#define MT_EXP_ACK_TIME			0x1380

#define MT_TX_PWR_CFG_0_EXT		0x1390
#define MT_TX_PWR_CFG_1_EXT		0x1394

#define MT_TX_FBK_LIMIT			0x1398
#define MT_TX_FBK_LIMIT_MPDU_FBK	GENMASK(7, 0)
#define MT_TX_FBK_LIMIT_AMPDU_FBK	GENMASK(15, 8)
#define MT_TX_FBK_LIMIT_MPDU_UP_CLEAR	BIT(16)
#define MT_TX_FBK_LIMIT_AMPDU_UP_CLEAR	BIT(17)
#define MT_TX_FBK_LIMIT_RATE_LUT	BIT(18)

#define MT_TX0_RF_GAIN_CORR		0x13a0
#define MT_TX1_RF_GAIN_CORR		0x13a4

#define MT_TX_ALC_CFG_0			0x13b0
#define MT_TX_ALC_CFG_0_CH_INIT_0	GENMASK(5, 0)
#define MT_TX_ALC_CFG_0_CH_INIT_1	GENMASK(13, 8)
#define MT_TX_ALC_CFG_0_LIMIT_0		GENMASK(21, 16)
#define MT_TX_ALC_CFG_0_LIMIT_1		GENMASK(29, 24)

#define MT_TX_ALC_CFG_1			0x13b4
#define MT_TX_ALC_CFG_1_TEMP_COMP	GENMASK(5, 0)

#define MT_TX_ALC_CFG_2			0x13a8
#define MT_TX_ALC_CFG_2_TEMP_COMP	GENMASK(5, 0)

#define MT_TX_ALC_CFG_3			0x13ac
#define MT_TX_ALC_CFG_4			0x13c0
#define MT_TX_ALC_CFG_4_LOWGAIN_CH_EN	BIT(31)

#define MT_TX_ALC_VGA3			0x13c8

#define MT_TX_PROT_CFG6			0x13e0
#define MT_TX_PROT_CFG7			0x13e4
#define MT_TX_PROT_CFG8			0x13e8

#define MT_PIFS_TX_CFG			0x13ec

#define MT_RX_FILTR_CFG			0x1400

#define MT_RX_FILTR_CFG_CRC_ERR		BIT(0)
#define MT_RX_FILTR_CFG_PHY_ERR		BIT(1)
#define MT_RX_FILTR_CFG_PROMISC		BIT(2)
#define MT_RX_FILTR_CFG_OTHER_BSS	BIT(3)
#define MT_RX_FILTR_CFG_VER_ERR		BIT(4)
#define MT_RX_FILTR_CFG_MCAST		BIT(5)
#define MT_RX_FILTR_CFG_BCAST		BIT(6)
#define MT_RX_FILTR_CFG_DUP		BIT(7)
#define MT_RX_FILTR_CFG_CFACK		BIT(8)
#define MT_RX_FILTR_CFG_CFEND		BIT(9)
#define MT_RX_FILTR_CFG_ACK		BIT(10)
#define MT_RX_FILTR_CFG_CTS		BIT(11)
#define MT_RX_FILTR_CFG_RTS		BIT(12)
#define MT_RX_FILTR_CFG_PSPOLL		BIT(13)
#define MT_RX_FILTR_CFG_BA		BIT(14)
#define MT_RX_FILTR_CFG_BAR		BIT(15)
#define MT_RX_FILTR_CFG_CTRL_RSV	BIT(16)

#define MT_LEGACY_BASIC_RATE		0x1408
#define MT_HT_BASIC_RATE		0x140c

#define MT_HT_CTRL_CFG			0x1410

#define MT_EXT_CCA_CFG			0x141c
#define MT_EXT_CCA_CFG_CCA0		GENMASK(1, 0)
#define MT_EXT_CCA_CFG_CCA1		GENMASK(3, 2)
#define MT_EXT_CCA_CFG_CCA2		GENMASK(5, 4)
#define MT_EXT_CCA_CFG_CCA3		GENMASK(7, 6)
#define MT_EXT_CCA_CFG_CCA_MASK		GENMASK(11, 8)
#define MT_EXT_CCA_CFG_ED_CCA_MASK	GENMASK(15, 12)

#define MT_TX_SW_CFG3			0x1478

#define MT_PN_PAD_MODE			0x150c

#define MT_TXOP_HLDR_ET			0x1608

#define MT_PROT_AUTO_TX_CFG		0x1648
#define MT_PROT_AUTO_TX_CFG_PROT_PADJ	GENMASK(11, 8)
#define MT_PROT_AUTO_TX_CFG_AUTO_PADJ	GENMASK(27, 24)

#define MT_TX_STAT_FIFO			0x1718
#define MT_TX_STAT_FIFO_VALID		BIT(0)
#define MT_TX_STAT_FIFO_SUCCESS		BIT(5)
#define MT_TX_STAT_FIFO_AGGR		BIT(6)
#define MT_TX_STAT_FIFO_ACKREQ		BIT(7)
#define MT_TX_STAT_FIFO_WCID		GENMASK(15, 8)
#define MT_TX_STAT_FIFO_RATE		GENMASK(31, 16)

#define MT_TX_AGG_CNT_BASE0		0x1720
#define MT_TX_AGG_CNT_BASE1		0x174c

#define MT_TX_AGG_CNT(_id)		((_id) < 8 ?			\
					 MT_TX_AGG_CNT_BASE0 + ((_id) << 2) : \
					 MT_TX_AGG_CNT_BASE1 + ((_id - 8) << 2))

#define MT_TX_STAT_FIFO_EXT		0x1798
#define MT_TX_STAT_FIFO_EXT_RETRY	GENMASK(7, 0)
#define MT_TX_STAT_FIFO_EXT_PKTID	GENMASK(15, 8)

#define MT_BBP_CORE_BASE		0x2000
#define MT_BBP_IBI_BASE			0x2100
#define MT_BBP_AGC_BASE			0x2300
#define MT_BBP_TXC_BASE			0x2400
#define MT_BBP_RXC_BASE			0x2500
#define MT_BBP_TXO_BASE			0x2600
#define MT_BBP_TXBE_BASE		0x2700
#define MT_BBP_RXFE_BASE		0x2800
#define MT_BBP_RXO_BASE			0x2900
#define MT_BBP_DFS_BASE			0x2a00
#define MT_BBP_TR_BASE			0x2b00
#define MT_BBP_CAL_BASE			0x2c00
#define MT_BBP_DSC_BASE			0x2e00
#define MT_BBP_PFMU_BASE		0x2f00

#define MT_BBP(_type, _n)		(MT_BBP_##_type##_BASE + ((_n) << 2))

#define MT_BBP_CORE_R1_BW		GENMASK(4, 3)

#define MT_BBP_AGC_R0_CTRL_CHAN		GENMASK(9, 8)
#define MT_BBP_AGC_R0_BW		GENMASK(14, 12)

/* AGC, R4/R5 */
#define MT_BBP_AGC_LNA_GAIN		GENMASK(21, 16)

/* AGC, R8/R9 */
#define MT_BBP_AGC_GAIN			GENMASK(14, 8)

#define MT_BBP_AGC20_RSSI0		GENMASK(7, 0)
#define MT_BBP_AGC20_RSSI1		GENMASK(15, 8)

#define MT_BBP_TXBE_R0_CTRL_CHAN	GENMASK(1, 0)

#define MT_WCID_ADDR_BASE		0x1800
#define MT_WCID_ADDR(_n)		(MT_WCID_ADDR_BASE + (_n) * 8)

#define MT_SRAM_BASE			0x4000

#define MT_WCID_KEY_BASE		0x8000
#define MT_WCID_KEY(_n)			(MT_WCID_KEY_BASE + (_n) * 32)

#define MT_WCID_IV_BASE			0xa000
#define MT_WCID_IV(_n)			(MT_WCID_IV_BASE + (_n) * 8)

#define MT_WCID_ATTR_BASE		0xa800
#define MT_WCID_ATTR(_n)		(MT_WCID_ATTR_BASE + (_n) * 4)

#define MT_WCID_ATTR_PAIRWISE		BIT(0)
#define MT_WCID_ATTR_PKEY_MODE		GENMASK(3, 1)
#define MT_WCID_ATTR_BSS_IDX		GENMASK(6, 4)
#define MT_WCID_ATTR_RXWI_UDF		GENMASK(9, 7)
#define MT_WCID_ATTR_PKEY_MODE_EXT	BIT(10)
#define MT_WCID_ATTR_BSS_IDX_EXT	BIT(11)
#define MT_WCID_ATTR_WAPI_MCBC		BIT(15)
#define MT_WCID_ATTR_WAPI_KEYID		GENMASK(31, 24)

#define MT_SKEY_BASE_0			0xac00
#define MT_SKEY_BASE_1			0xb400
#define MT_SKEY_0(_bss, _idx)		(MT_SKEY_BASE_0 + (4 * (_bss) + _idx) * 32)
#define MT_SKEY_1(_bss, _idx)		(MT_SKEY_BASE_1 + (4 * ((_bss) & 7) + _idx) * 32)
#define MT_SKEY(_bss, _idx)		((_bss & 8) ? MT_SKEY_1(_bss, _idx) : MT_SKEY_0(_bss, _idx))

#define MT_SKEY_MODE_BASE_0		0xb000
#define MT_SKEY_MODE_BASE_1		0xb3f0
#define MT_SKEY_MODE_0(_bss)		(MT_SKEY_MODE_BASE_0 + ((_bss / 2) << 2))
#define MT_SKEY_MODE_1(_bss)		(MT_SKEY_MODE_BASE_1 + ((((_bss) & 7) / 2) << 2))
#define MT_SKEY_MODE(_bss)		((_bss & 8) ? MT_SKEY_MODE_1(_bss) : MT_SKEY_MODE_0(_bss))
#define MT_SKEY_MODE_MASK		GENMASK(3, 0)
#define MT_SKEY_MODE_SHIFT(_bss, _idx)	(4 * ((_idx) + 4 * (_bss & 1)))

#define MT_BEACON_BASE			0xc000

#define MT_TEMP_SENSOR			0x1d000
#define MT_TEMP_SENSOR_VAL		GENMASK(6, 0)

struct mt76_wcid_addr {
	u8 macaddr[6];
	__le16 ba_mask;
} __packed __aligned(4);

struct mt76_wcid_key {
	u8 key[16];
	u8 tx_mic[8];
	u8 rx_mic[8];
} __packed __aligned(4);

enum mt76x2_cipher_type {
	MT_CIPHER_NONE,
	MT_CIPHER_WEP40,
	MT_CIPHER_WEP104,
	MT_CIPHER_TKIP,
	MT_CIPHER_AES_CCMP,
	MT_CIPHER_CKIP40,
	MT_CIPHER_CKIP104,
	MT_CIPHER_CKIP128,
	MT_CIPHER_WAPI,
};

#endif
