/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*! @brief Direction type  */
typedef enum _pin_mux_direction
{
  kPIN_MUX_DirectionInput = 0U,         /* Input direction */
  kPIN_MUX_DirectionOutput = 1U,        /* Output direction */
  kPIN_MUX_DirectionInputOrOutput = 2U  /* Input or output direction */
} pin_mux_direction_t;

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif

/*!
 * @brief Calls initialization functions.
 *
 */
void BOARD_InitBootPins(void);

/* GPIO_AD_B0_15 (coord L10), CAN2_RX/U12[4] */
/* Routed pin properties */
#define BOARD_INITPINS_CAN2_CAN2_RX_PERIPHERAL                              CAN2   /*!< Peripheral name */
#define BOARD_INITPINS_CAN2_CAN2_RX_SIGNAL                                    RX   /*!< Signal name */

/* GPIO_AD_B0_14 (coord H14), CAN2_TX/U12[1] */
/* Routed pin properties */
#define BOARD_INITPINS_CAN2_CAN2_TX_PERIPHERAL                              CAN2   /*!< Peripheral name */
#define BOARD_INITPINS_CAN2_CAN2_TX_SIGNAL                                    TX   /*!< Signal name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins_CAN2(void);

/* GPIO_AD_B0_13 (coord L14), UART1_RXD */
/* Routed pin properties */
#define BOARD_INITPINS_UART1_UART1_RXD_PERIPHERAL                        LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_UART1_UART1_RXD_SIGNAL                                 RX   /*!< Signal name */

/* GPIO_AD_B0_12 (coord K14), UART1_TXD */
/* Routed pin properties */
#define BOARD_INITPINS_UART1_UART1_TXD_PERIPHERAL                        LPUART1   /*!< Peripheral name */
#define BOARD_INITPINS_UART1_UART1_TXD_SIGNAL                                 TX   /*!< Signal name */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins_UART1(void);

/* GPIO_AD_B1_11 (coord J13), SAI1_RX_BCLK/CSI_D6/J35[7]/J23[2] */
/* Routed pin properties */
#define BOARD_INITPINS_ADC1_CH0_CSI_D6_PERIPHERAL                           ADC1   /*!< Peripheral name */
#define BOARD_INITPINS_ADC1_CH0_CSI_D6_SIGNAL                                 IN   /*!< Signal name */
#define BOARD_INITPINS_ADC1_CH0_CSI_D6_CHANNEL                                0U   /*!< Signal channel */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins_ADC1_ch0(void);

/* GPIO_AD_B1_04 (coord L12), CSI_PIXCLK/J35[8]/J23[3] */
/* Routed pin properties */
#define BOARD_INITPINS_ADC1_CH9_CSI_PIXCLK_PERIPHERAL                       ADC1   /*!< Peripheral name */
#define BOARD_INITPINS_ADC1_CH9_CSI_PIXCLK_SIGNAL                             IN   /*!< Signal name */
#define BOARD_INITPINS_ADC1_CH9_CSI_PIXCLK_CHANNEL                            9U   /*!< Signal channel */

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins_ADC1_ch9(void);

/*!
 * @brief Configures pin routing and optionally pin electrical features.
 *
 */
void BOARD_InitPins_PWM(void);

#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
