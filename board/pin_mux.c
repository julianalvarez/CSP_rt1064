/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v14.0
processor: MIMXRT1064xxxxA
package_id: MIMXRT1064DVL6A
mcu_data: ksdk2_0
processor_version: 14.0.0
board: MIMXRT1064-EVK
pin_labels:
- {pin_num: E3, pin_signal: GPIO_EMC_00, label: SEMC_D0, identifier: SEMC_D0}
- {pin_num: F3, pin_signal: GPIO_EMC_01, label: SEMC_D1, identifier: SEMC_D1}
- {pin_num: F4, pin_signal: GPIO_EMC_02, label: SEMC_D2, identifier: SEMC_D2}
- {pin_num: F2, pin_signal: GPIO_EMC_04, label: SEMC_D4, identifier: SEMC_D4}
- {pin_num: G4, pin_signal: GPIO_EMC_03, label: SEMC_D3, identifier: SEMC_D3}
- {pin_num: G5, pin_signal: GPIO_EMC_05, label: SEMC_D5, identifier: SEMC_D5}
- {pin_num: H5, pin_signal: GPIO_EMC_06, label: SEMC_D6, identifier: SEMC_D6}
- {pin_num: H4, pin_signal: GPIO_EMC_07, label: SEMC_D7, identifier: SEMC_D7}
- {pin_num: H3, pin_signal: GPIO_EMC_08, label: SEMC_DM0, identifier: SEMC_DM0}
- {pin_num: C2, pin_signal: GPIO_EMC_09, label: SEMC_A0, identifier: SEMC_A0}
- {pin_num: G1, pin_signal: GPIO_EMC_10, label: SEMC_A1, identifier: SEMC_A1}
- {pin_num: G3, pin_signal: GPIO_EMC_11, label: SEMC_A2, identifier: SEMC_A2}
- {pin_num: H1, pin_signal: GPIO_EMC_12, label: SEMC_A3, identifier: SEMC_A3}
- {pin_num: A6, pin_signal: GPIO_EMC_13, label: SEMC_A4, identifier: SEMC_A4}
- {pin_num: B6, pin_signal: GPIO_EMC_14, label: SEMC_A5, identifier: SEMC_A5}
- {pin_num: B1, pin_signal: GPIO_EMC_15, label: SEMC_A6, identifier: SEMC_A6}
- {pin_num: A5, pin_signal: GPIO_EMC_16, label: SEMC_A7, identifier: SEMC_A7}
- {pin_num: A4, pin_signal: GPIO_EMC_17, label: SEMC_A8, identifier: SEMC_A8}
- {pin_num: B2, pin_signal: GPIO_EMC_18, label: SEMC_A9, identifier: SEMC_A9}
- {pin_num: B4, pin_signal: GPIO_EMC_19, label: SEMC_A11, identifier: SEMC_A11}
- {pin_num: G2, pin_signal: GPIO_EMC_23, label: SEMC_A10, identifier: SEMC_A10}
- {pin_num: A3, pin_signal: GPIO_EMC_20, label: SEMC_A12, identifier: SEMC_A12}
- {pin_num: C1, pin_signal: GPIO_EMC_21, label: SEMC_BA0, identifier: SEMC_BA0}
- {pin_num: F1, pin_signal: GPIO_EMC_22, label: SEMC_BA1, identifier: SEMC_BA1}
- {pin_num: D3, pin_signal: GPIO_EMC_24, label: SEMC_CAS, identifier: SEMC_CAS}
- {pin_num: D2, pin_signal: GPIO_EMC_25, label: SEMC_RAS, identifier: SEMC_RAS}
- {pin_num: B3, pin_signal: GPIO_EMC_26, label: SEMC_CLK, identifier: SEMC_CLK}
- {pin_num: A2, pin_signal: GPIO_EMC_27, label: SEMC_CKE, identifier: SEMC_CKE}
- {pin_num: D1, pin_signal: GPIO_EMC_28, label: SEMC_WE, identifier: SEMC_WE}
- {pin_num: E1, pin_signal: GPIO_EMC_29, label: SEMC_CS0, identifier: SEMC_CS0}
- {pin_num: C6, pin_signal: GPIO_EMC_30, label: SEMC_D8, identifier: SEMC_D8}
- {pin_num: C5, pin_signal: GPIO_EMC_31, label: SEMC_D9, identifier: SEMC_D9}
- {pin_num: D5, pin_signal: GPIO_EMC_32, label: SEMC_D10, identifier: SEMC_D10}
- {pin_num: C4, pin_signal: GPIO_EMC_33, label: SEMC_D11, identifier: SEMC_D11}
- {pin_num: D4, pin_signal: GPIO_EMC_34, label: SEMC_D12, identifier: SEMC_D12}
- {pin_num: E5, pin_signal: GPIO_EMC_35, label: SEMC_D13, identifier: SEMC_D13}
- {pin_num: C3, pin_signal: GPIO_EMC_36, label: SEMC_D14, identifier: SEMC_D14}
- {pin_num: E4, pin_signal: GPIO_EMC_37, label: SEMC_D15, identifier: SEMC_D15}
- {pin_num: D6, pin_signal: GPIO_EMC_38, label: SEMC_DM1, identifier: SEMC_DM1}
- {pin_num: B7, pin_signal: GPIO_EMC_39, label: SEMC_DQS, identifier: SEMC_DQS}
- {pin_num: A7, pin_signal: GPIO_EMC_40, label: ENET_MDC, identifier: ENET_MDC}
- {pin_num: C7, pin_signal: GPIO_EMC_41, label: ENET_MDIO, identifier: ENET_MDIO}
- {pin_num: D7, pin_signal: GPIO_B0_00, label: LCDIF_CLK, identifier: LCDIF_CLK}
- {pin_num: E7, pin_signal: GPIO_B0_01, label: LCDIF_ENABLE, identifier: LCDIF_ENABLE}
- {pin_num: E8, pin_signal: GPIO_B0_02, label: LCDIF_HSYNC, identifier: LCDIF_HSYNC}
- {pin_num: D8, pin_signal: GPIO_B0_03, label: LCDIF_VSYNC, identifier: LCDIF_VSYNC}
- {pin_num: C8, pin_signal: GPIO_B0_04, label: 'LCDIF_D0/BT_CFG[0]', identifier: LCDIF_D0}
- {pin_num: B8, pin_signal: GPIO_B0_05, label: 'LCDIF_D1/BT_CFG[1]', identifier: LCDIF_D1}
- {pin_num: A8, pin_signal: GPIO_B0_06, label: 'LCDIF_D2/BT_CFG[2]', identifier: LCDIF_D2}
- {pin_num: A9, pin_signal: GPIO_B0_07, label: 'LCDIF_D3/BT_CFG[3]', identifier: LCDIF_D3}
- {pin_num: B9, pin_signal: GPIO_B0_08, label: 'LCDIF_D4/BT_CFG[4]', identifier: LCDIF_D4}
- {pin_num: C9, pin_signal: GPIO_B0_09, label: 'LCDIF_D5/BT_CFG[5]', identifier: LCDIF_D5}
- {pin_num: D9, pin_signal: GPIO_B0_10, label: 'LCDIF_D6/BT_CFG[6]', identifier: LCDIF_D6}
- {pin_num: A10, pin_signal: GPIO_B0_11, label: 'LCDIF_D7/BT_CFG[7]', identifier: LCDIF_D7}
- {pin_num: C10, pin_signal: GPIO_B0_12, label: 'LCDIF_D8/BT_CFG[8]', identifier: LCDIF_D8}
- {pin_num: D10, pin_signal: GPIO_B0_13, label: 'LCDIF_D9/BT_CFG[9]', identifier: LCDIF_D9}
- {pin_num: E10, pin_signal: GPIO_B0_14, label: 'LCDIF_D10/BT_CFG[10]', identifier: LCDIF_D10}
- {pin_num: E11, pin_signal: GPIO_B0_15, label: 'LCDIF_D11/BT_CFG[11]', identifier: LCDIF_D11}
- {pin_num: A11, pin_signal: GPIO_B1_00, label: LCDIF_D12, identifier: LCDIF_D12}
- {pin_num: B11, pin_signal: GPIO_B1_01, label: LCDIF_D13, identifier: LCDIF_D13}
- {pin_num: C11, pin_signal: GPIO_B1_02, label: LCDIF_D14, identifier: LCDIF_D14}
- {pin_num: D11, pin_signal: GPIO_B1_03, label: LCDIF_D15, identifier: LCDIF_D15}
- {pin_num: E12, pin_signal: GPIO_B1_04, label: ENET_RXD0, identifier: ENET_RXD0}
- {pin_num: D12, pin_signal: GPIO_B1_05, label: ENET_RXD1, identifier: ENET_RXD1}
- {pin_num: C12, pin_signal: GPIO_B1_06, label: ENET_CRS_DV, identifier: ENET_CRS_DV}
- {pin_num: B12, pin_signal: GPIO_B1_07, label: ENET_TXD0, identifier: ENET_TXD0}
- {pin_num: A12, pin_signal: GPIO_B1_08, label: ENET_TXD1, identifier: ENET_TXD1}
- {pin_num: A13, pin_signal: GPIO_B1_09, label: ENET_TXEN, identifier: ENET_TXEN}
- {pin_num: B13, pin_signal: GPIO_B1_10, label: ENET_TX_CLK, identifier: ENET_TX_CLK}
- {pin_num: C13, pin_signal: GPIO_B1_11, label: ENET_RXER, identifier: ENET_RXER}
- {pin_num: D13, pin_signal: GPIO_B1_12, label: SD_CD_SW, identifier: SD_CD_SW}
- {pin_num: D14, pin_signal: GPIO_B1_13, label: WDOG_B, identifier: WDOG_B}
- {pin_num: C14, pin_signal: GPIO_B1_14, label: SD0_VSELECT, identifier: SD0_VSELECT}
- {pin_num: B14, pin_signal: GPIO_B1_15, label: USB_HOST_PWR/BACKLIGHT_CTL, identifier: BACKLIGHT_CTL}
- {pin_num: E9, pin_signal: NVCC_GPIO0, label: DCDC_3V3/NVCC_GPIO_3V3}
- {pin_num: F10, pin_signal: NVCC_GPIO1, label: DCDC_3V3/NVCC_GPIO_3V3}
- {pin_num: J10, pin_signal: NVCC_GPIO2, label: DCDC_3V3/NVCC_GPIO_3V3}
- {pin_num: M14, pin_signal: GPIO_AD_B0_00, label: 'USB_HOST_OC/J24[10]'}
- {pin_num: H10, pin_signal: GPIO_AD_B0_01, label: 'USB_OTG1_ID/J24[9]'}
- {pin_num: M11, pin_signal: GPIO_AD_B0_02, label: 'USB_OTG1_PWR/J24[2]'}
- {pin_num: G11, pin_signal: GPIO_AD_B0_03, label: 'USB_OTG1_OC/J24[1]'}
- {pin_num: F11, pin_signal: GPIO_AD_B0_04, label: 'CSI_PWDN/J35[17]/BOOT_MODE[0]', identifier: CSI_PWDN}
- {pin_num: G14, pin_signal: GPIO_AD_B0_05, label: 'CAN_STBY/BOOT_MODE[1]/Flash_RST/U12[8]', identifier: CAN_STBY}
- {pin_num: E14, pin_signal: GPIO_AD_B0_06, label: 'JTAG_TMS/J21[7]/SWD_DIO'}
- {pin_num: F12, pin_signal: GPIO_AD_B0_07, label: 'JTAG_TCK/J21[9]/SWD_CLK'}
- {pin_num: F13, pin_signal: GPIO_AD_B0_08, label: JTAG_MOD}
- {pin_num: F14, pin_signal: GPIO_AD_B0_09, label: 'JTAG_TDI/J21[5]/ENET_RST/J22[5]'}
- {pin_num: G13, pin_signal: GPIO_AD_B0_10, label: 'JTAG_TDO/J21[13]/INT1_COMBO/ENET_INT/J22[6]/U32[11]', identifier: INT1_COMBO}
- {pin_num: G10, pin_signal: GPIO_AD_B0_11, label: 'JTAG_nTRST/J21[3]/INT2_COMBO/LCD_TOUCH_INT/J22[3]/U32[9]', identifier: INT2_COMBO}
- {pin_num: K14, pin_signal: GPIO_AD_B0_12, label: UART1_TXD, identifier: UART1_TXD}
- {pin_num: L14, pin_signal: GPIO_AD_B0_13, label: UART1_RXD, identifier: UART1_RXD}
- {pin_num: H14, pin_signal: GPIO_AD_B0_14, label: 'CAN2_TX/U12[1]', identifier: CAN2_TX}
- {pin_num: L10, pin_signal: GPIO_AD_B0_15, label: 'CAN2_RX/U12[4]', identifier: CAN2_RX}
- {pin_num: J11, pin_signal: GPIO_AD_B1_00, label: 'I2C1_SCL/CSI_I2C_SCL/J35[20]/J23[6]/U13[17]/U32[4]', identifier: I2C_SCL_FXOS8700CQ;CSI_I2C_SCL}
- {pin_num: K11, pin_signal: GPIO_AD_B1_01, label: 'I2C1_SDA/CSI_I2C_SDA/J35[22]/J23[5]/U13[18]/U32[6]', identifier: I2C_SDA_FXOS8700CQ;CSI_I2C_SDA}
- {pin_num: L11, pin_signal: GPIO_AD_B1_02, label: 'SPDIF_OUT/J22[7]', identifier: SPDIF_OUT}
- {pin_num: M12, pin_signal: GPIO_AD_B1_03, label: 'SPDIF_IN/J22[8]', identifier: SPDIF_IN}
- {pin_num: H13, pin_signal: GPIO_AD_B1_08, label: 'AUD_INT/CSI_D9//J35[13]/J22[4]', identifier: CSI_D9}
- {pin_num: M13, pin_signal: GPIO_AD_B1_09, label: 'SAI1_MCLK/CSI_D8/J35[11]', identifier: CSI_D8}
- {pin_num: L13, pin_signal: GPIO_AD_B1_10, label: 'SAI1_RX_SYNC/CSI_D7/J35[9]/J23[1]', identifier: CSI_D7}
- {pin_num: J13, pin_signal: GPIO_AD_B1_11, label: 'SAI1_RX_BCLK/CSI_D6/J35[7]/J23[2]', identifier: CSI_D6}
- {pin_num: H12, pin_signal: GPIO_AD_B1_12, label: 'SAI1_RXD/CSI_D5/J35[5]/U13[16]', identifier: CSI_D5}
- {pin_num: H11, pin_signal: GPIO_AD_B1_13, label: 'SAI1_TXD/CSI_D4/J35[3]/U13[14]', identifier: CSI_D4}
- {pin_num: G12, pin_signal: GPIO_AD_B1_14, label: 'SAI1_TX_BCLK/CSI_D3/J35[4]/U13[12]', identifier: CSI_D3}
- {pin_num: J14, pin_signal: GPIO_AD_B1_15, label: 'SAI1_TX_SYNC/CSI_D2/J35[6]/U13[13]', identifier: CSI_D2}
- {pin_num: J4, pin_signal: GPIO_SD_B0_00, label: 'SD1_CMD/J24[6]', identifier: SD1_CMD}
- {pin_num: J3, pin_signal: GPIO_SD_B0_01, label: 'SD1_CLK/J24[3]', identifier: SD1_CLK}
- {pin_num: J1, pin_signal: GPIO_SD_B0_02, label: 'SD1_D0/J24[4]/SPI_MOSI/PWM', identifier: SD1_D0}
- {pin_num: K1, pin_signal: GPIO_SD_B0_03, label: 'SD1_D1/J24[5]/SPI_MISO', identifier: SD1_D1}
- {pin_num: H2, pin_signal: GPIO_SD_B0_04, label: SD1_D2, identifier: SD1_D2}
- {pin_num: J2, pin_signal: GPIO_SD_B0_05, label: SD1_D3, identifier: SD1_D3}
- {pin_num: L5, pin_signal: GPIO_SD_B1_00, label: FlexSPI_D3_B, identifier: FlexSPI_D3_B}
- {pin_num: M5, pin_signal: GPIO_SD_B1_01, label: FlexSPI_D2_B, identifier: FlexSPI_D2_B}
- {pin_num: M3, pin_signal: GPIO_SD_B1_02, label: FlexSPI_D1_B, identifier: FlexSPI_D1_B}
- {pin_num: M4, pin_signal: GPIO_SD_B1_03, label: FlexSPI_D0_B, identifier: FlexSPI_D0_B}
- {pin_num: P2, pin_signal: GPIO_SD_B1_04, label: FlexSPI_CLK_B, identifier: FlexSPI_CLK_B}
- {pin_num: N3, pin_signal: GPIO_SD_B1_05, label: FlexSPI_DQS, identifier: FlexSPI_DQS}
- {pin_num: L3, pin_signal: GPIO_SD_B1_06, label: FlexSPI_SS0, identifier: FlexSPI_SS0}
- {pin_num: L4, pin_signal: GPIO_SD_B1_07, label: FlexSPI_CLK, identifier: FlexSPI_CLK}
- {pin_num: P3, pin_signal: GPIO_SD_B1_08, label: FlexSPI_D0_A, identifier: FlexSPI_D0_A}
- {pin_num: N4, pin_signal: GPIO_SD_B1_09, label: FlexSPI_D1_A, identifier: FlexSPI_D1_A}
- {pin_num: P4, pin_signal: GPIO_SD_B1_10, label: FlexSPI_D2_A, identifier: FlexSPI_D2_A}
- {pin_num: P5, pin_signal: GPIO_SD_B1_11, label: FlexSPI_D3_A, identifier: FlexSPI_D3_A}
- {pin_num: M8, pin_signal: USB_OTG1_DN, label: OTG1_DN, identifier: OTG1_DN}
- {pin_num: L8, pin_signal: USB_OTG1_DP, label: OTG1_DP, identifier: OTG1_DP}
- {pin_num: N7, pin_signal: USB_OTG2_DN, label: OTG2_DN, identifier: OTG2_DN}
- {pin_num: P7, pin_signal: USB_OTG2_DP, label: OTG2_DP, identifier: OTG2_DP}
- {pin_num: K8, pin_signal: VDD_USB_CAP, label: VDD_USB_3V}
- {pin_num: N6, pin_signal: USB_OTG1_VBUS, label: 5V_USB_OTG}
- {pin_num: P6, pin_signal: USB_OTG2_VBUS, label: 5V_USB_HS}
- {pin_num: L12, pin_signal: GPIO_AD_B1_04, label: 'CSI_PIXCLK/J35[8]/J23[3]', identifier: CSI_PIXCLK}
- {pin_num: K12, pin_signal: GPIO_AD_B1_05, label: 'CSI_MCLK/J35[12]/J23[4]', identifier: CSI_MCLK}
- {pin_num: J12, pin_signal: GPIO_AD_B1_06, label: 'CSI_VSYNC/J35[18]/J22[2]/UART_TX', identifier: CSI_VSYNC}
- {pin_num: K10, pin_signal: GPIO_AD_B1_07, label: 'CSI_HSYNC/J35[16]/J22[1]/UART_RX', identifier: CSI_HSYNC}
- {pin_num: M7, pin_signal: POR_B, label: 'RST_TGTMCU_B/POR_B/J21[15]', identifier: RST_TGTMCU_B;POR_B}
- {pin_num: N14, pin_signal: VDDA_ADC_3P3, label: VDDA_ADC_3P3_MCU}
- {pin_num: P12, pin_signal: VDD_HIGH_IN, label: VDD_HIGH_IN_MCU}
- {pin_num: M9, pin_signal: VDD_SNVS_IN, label: VDD_SNVS_IN}
- {pin_num: F6, pin_signal: VDD_SOC_IN0, label: VDD_SOC_IN}
- {pin_num: H6, pin_signal: VDD_SOC_IN2, label: VDD_SOC_IN}
- {pin_num: G6, pin_signal: VDD_SOC_IN1, label: VDD_SOC_IN}
- {pin_num: F7, pin_signal: VDD_SOC_IN3, label: VDD_SOC_IN}
- {pin_num: F8, pin_signal: VDD_SOC_IN4, label: VDD_SOC_IN}
- {pin_num: F9, pin_signal: VDD_SOC_IN5, label: VDD_SOC_IN}
- {pin_num: G9, pin_signal: VDD_SOC_IN6, label: VDD_SOC_IN}
- {pin_num: H9, pin_signal: VDD_SOC_IN7, label: VDD_SOC_IN}
- {pin_num: J9, pin_signal: VDD_SOC_IN8, label: VDD_SOC_IN}
- {pin_num: P1, pin_signal: VSS1, label: GND}
- {pin_num: E2, pin_signal: VSS2, label: GND}
- {pin_num: K2, pin_signal: VSS3, label: GND}
- {pin_num: B5, pin_signal: VSS4, label: GND}
- {pin_num: N5, pin_signal: VSS5, label: GND}
- {pin_num: G7, pin_signal: VSS6, label: GND}
- {pin_num: H7, pin_signal: VSS7, label: GND}
- {pin_num: J7, pin_signal: VSS8, label: GND}
- {pin_num: G8, pin_signal: VSS9, label: GND}
- {pin_num: H8, pin_signal: VSS10, label: GND}
- {pin_num: J8, pin_signal: VSS11, label: GND}
- {pin_num: N8, pin_signal: VSS12, label: GND}
- {pin_num: L9, pin_signal: VSS13, label: GND}
- {pin_num: B10, pin_signal: VSS14, label: GND}
- {pin_num: E13, pin_signal: VSS15, label: GND}
- {pin_num: K13, pin_signal: VSS16, label: GND}
- {pin_num: A14, pin_signal: VSS17, label: GND}
- {pin_num: P14, pin_signal: VSS18, label: GND}
- {pin_num: A1, pin_signal: VSS0, label: GND}
- {pin_num: J6, pin_signal: NVCC_SD0, label: NVCC_SD, identifier: NVCC_SD}
- {pin_num: K5, pin_signal: NVCC_SD1, label: FLASH_VCC, identifier: FLASH_VCC}
- {pin_num: F5, pin_signal: NVCC_EMC0, label: DCDC_3V3}
- {pin_num: E6, pin_signal: NVCC_EMC1, label: DCDC_3V3}
- {pin_num: L6, pin_signal: WAKEUP, label: SD_PWREN, identifier: SD_PWREN}
- {pin_num: L1, pin_signal: DCDC_IN0, label: MCU_DCDC_IN_3V3}
- {pin_num: L2, pin_signal: DCDC_IN1, label: MCU_DCDC_IN_3V3}
- {pin_num: K4, pin_signal: DCDC_IN_Q, label: MCU_DCDC_IN_3V3}
- {pin_num: M1, pin_signal: DCDC_LP0, label: VDD_SOC_IN}
- {pin_num: M2, pin_signal: DCDC_LP1, label: VDD_SOC_IN}
- {pin_num: P11, pin_signal: XTALI, label: XTALI, identifier: XTALI}
- {pin_num: N11, pin_signal: XTALO, label: XTALO, identifier: XTALO}
- {pin_num: N9, pin_signal: RTC_XTALI, label: RTC_XTALI, identifier: RTC_XTALI}
- {pin_num: P9, pin_signal: RTC_XTALO, label: RTC_XTALO, identifier: RTC_XTALO}
- {pin_num: N1, pin_signal: DCDC_GND0, label: GND}
- {pin_num: N2, pin_signal: DCDC_GND1, label: GND}
- {pin_num: J5, pin_signal: DCDC_SENSE, label: VDD_SOC_IN}
- {pin_num: K3, pin_signal: DCDC_PSWITCH, label: MCU_DCDC_IN_3V3}
- {pin_num: K7, pin_signal: PMIC_ON_REQ, label: PMIC_ON_REQ, identifier: PMIC_ON_REQ}
- {pin_num: L7, pin_signal: PMIC_STBY_REQ, label: PERI_PWREN, identifier: PERI_PWREN}
- {pin_num: M6, pin_signal: ONOFF, label: ONOFF, identifier: ONOFF}
- {pin_num: K6, pin_signal: TEST_MODE, label: GND}
- {pin_num: P10, pin_signal: NVCC_PLL, label: VDDA_1P1_CAP}
- {pin_num: P8, pin_signal: VDD_HIGH_CAP, label: VDDA_2P5_CAP}
- {pin_num: K9, pin_signal: NGND_KEL0, label: GND}
- {pin_num: M10, pin_signal: VDD_SNVS_CAP, label: GND}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 * 
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 * 
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void) {
}

/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins_CAN2:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'false'}
- pin_list:
  - {pin_num: L10, peripheral: CAN2, signal: RX, pin_signal: GPIO_AD_B0_15}
  - {pin_num: H14, peripheral: CAN2, signal: TX, pin_signal: GPIO_AD_B0_14}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins_CAN2
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins_CAN2(void) {
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_14_FLEXCAN2_TX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_15_FLEXCAN2_RX, 0U); 
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins_UART1:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'false'}
- pin_list:
  - {pin_num: L14, peripheral: LPUART1, signal: RX, pin_signal: GPIO_AD_B0_13}
  - {pin_num: K14, peripheral: LPUART1, signal: TX, pin_signal: GPIO_AD_B0_12}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins_UART1
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins_UART1(void) {
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_12_LPUART1_TX, 0U); 
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B0_13_LPUART1_RX, 0U); 
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins_ADC1_ch0:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'false'}
- pin_list:
  - {pin_num: J13, peripheral: ADC1, signal: 'IN, 0', pin_signal: GPIO_AD_B1_11}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins_ADC1_ch0
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins_ADC1_ch0(void) {
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_11_GPIO1_IO27, 0U); 
}


/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins_ADC1_ch9:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'false'}
- pin_list:
  - {pin_num: L12, peripheral: ADC1, signal: 'IN, 9', pin_signal: GPIO_AD_B1_04}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins_ADC1_ch9
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins_ADC1_ch9(void) {
  IOMUXC_SetPinMux(IOMUXC_GPIO_AD_B1_04_GPIO1_IO20, 0U); 
}

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
