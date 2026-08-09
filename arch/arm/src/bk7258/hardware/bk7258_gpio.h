/****************************************************************************
 * arch/arm/src/bk7258/hardware/bk7258_gpio.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_BK7258_HARDWARE_BK7258_GPIO_H
#define __ARCH_ARM_SRC_BK7258_HARDWARE_BK7258_GPIO_H

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* AON GPIO register base (bk7258_memorymap.h: BK7258_AON_GPIO_BASE) */

#define BK7258_GPIO_CFG(n)       (BK7258_AON_GPIO_BASE + (n) * 4)

/* Per-GPIO config register bits (from ARMINO gpio_struct.h) */

#define GPIO_CFG_INPUT           (1u << 0) /* bit[0] gpio_input (RO) */
#define GPIO_CFG_OUTPUT          (1u << 1) /* bit[1] gpio_output (R/W) */
#define GPIO_CFG_INPUT_EN        (1u << 2) /* bit[2] input enable */
#define GPIO_CFG_OUTPUT_EN       (1u << 3) /* bit[3] output enable (ACTIVE LOW:
                                            * 0 = enable, 1 = disable.
                                            * Opposite of input_en which is
                                            * active high.) */
#define GPIO_CFG_PULL_UP         (1u << 4) /* bit[4] pull mode: 1=up */
#define GPIO_CFG_PULL_EN         (1u << 5) /* bit[5] pull enable */
#define GPIO_CFG_SECOND_FUNC     (1u << 6) /* bit[6] second function */

/* System GPIO function select registers (4 bits per pin, 8 pins per reg).
 * Pins 0-7:   @ BK7258_SYS_BASE + 0xC0
 * Pins 8-15:  @ BK7258_SYS_BASE + 0xC4
 * Pins 16-23: @ BK7258_SYS_BASE + 0xC8
 * Pins 24-31: @ BK7258_SYS_BASE + 0xCC
 * Pins 32-39: @ BK7258_SYS_BASE + 0xD0
 * Pins 40-47: @ BK7258_SYS_BASE + 0xD4
 * Pins 48-55: @ BK7258_SYS_BASE + 0xD8
 */

#define BK7258_SYS_GPIO_FUNC_BASE  (BK7258_SYS_BASE + 0xc0)
#define BK7258_SYS_GPIO_FUNC(pin)  (BK7258_SYS_GPIO_FUNC_BASE + ((pin) / 8) * 4)
#define BK7258_GPIO_FUNC_SHIFT(pin) (((pin) % 8) * 4)
#define BK7258_GPIO_FUNC_MASK       0xfu

#endif /* __ARCH_ARM_SRC_BK7258_HARDWARE_BK7258_GPIO_H */
