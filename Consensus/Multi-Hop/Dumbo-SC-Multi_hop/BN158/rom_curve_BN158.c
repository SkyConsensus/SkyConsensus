/*
 * Copyright (c) 2012-2020 MIRACL UK Ltd.
 *
 * This file is part of MIRACL Core
 * (see https://github.com/miracl/core).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "arch.h"
#include "ecp_BN158.h"

/* Curve BN254 - Pairing friendly BN curve */

/* Nogami's fast curve */

#if CHUNK==16

#error Not supported

#endif

#if CHUNK==32

const int CURVE_Cof_I_BN158= 1;
const BIG_160_28 CURVE_Cof_BN158= {0x1,0x0,0x0,0x0,0x0,0x0};
const int CURVE_B_I_BN158= 5;
const BIG_160_28 CURVE_B_BN158= {0x5,0x0,0x0,0x0,0x0,0x0};
const BIG_160_28 CURVE_Order_BN158= {0xF04200D,0xD59F209,0xF73FA14,0x9953CF6,0x27628C,0x24012};
const BIG_160_28 CURVE_Gx_BN158= {0xB04E012,0x72280A,0xFD3FB95,0x9953CF6,0x27628C,0x24012};
const BIG_160_28 CURVE_Gy_BN158= {0x2,0x0,0x0,0x0,0x0,0x0};
const BIG_160_28 CURVE_HTPC_BN158= {0x1,0x0,0x0,0x0,0x0,0x0};

const BIG_160_28 CURVE_Bnx_BN158= {0x801001,0x400,0x0,0x0,0x0,0x0};
const BIG_160_28 CURVE_Pxa_BN158= {0x33A5768,0x3B27650,0x3022922,0x1EECE2B,0xF882728,0x1EA35};
const BIG_160_28 CURVE_Pxb_BN158= {0x776A2F5,0x7B04ACE,0x14F9D68,0x5D05BA3,0x611EB92,0x23485};
const BIG_160_28 CURVE_Pya_BN158= {0x30CFE24,0x69AB26E,0xF92C435,0x1FB7A85,0xF906B6E,0x1C952};
const BIG_160_28 CURVE_Pyb_BN158= {0x8E8609D,0x9101773,0xA0F3EE2,0x8445B3B,0x9544ED8,0x23E28};
const BIG_160_28 CURVE_W_BN158[2]= {{0xA008003,0x3182600,0x600180,0x0,0x0,0x0},{0x1002001,0x800,0x0,0x0,0x0,0x0}};
const BIG_160_28 CURVE_SB_BN158[2][2]= {{{0xB00A004,0x3182E00,0x600180,0x0,0x0,0x0},{0x1002001,0x800,0x0,0x0,0x0,0x0}},{{0x1002001,0x800,0x0,0x0,0x0,0x0},{0x503A00A,0xA41CC09,0xF13F894,0x9953CF6,0x27628C,0x24012}}};
const BIG_160_28 CURVE_WB_BN158[4]= {{0x2801000,0x1080600,0x200080,0x0,0x0,0x0},{0x6815005,0xF907C02,0x2519090,0x120264,0x30,0x0},{0x380B003,0x7C84001,0x128C848,0x90132,0x18,0x0},{0x3803001,0x1080E00,0x200080,0x0,0x0,0x0}};
const BIG_160_28 CURVE_BB_BN158[4][4]= {{{0xE84100D,0xD59EE09,0xF73FA14,0x9953CF6,0x27628C,0x24012},{0xE84100C,0xD59EE09,0xF73FA14,0x9953CF6,0x27628C,0x24012},{0xE84100C,0xD59EE09,0xF73FA14,0x9953CF6,0x27628C,0x24012},{0x1002002,0x800,0x0,0x0,0x0,0x0}},{{0x1002001,0x800,0x0,0x0,0x0,0x0},{0xE84100C,0xD59EE09,0xF73FA14,0x9953CF6,0x27628C,0x24012},{0xE84100D,0xD59EE09,0xF73FA14,0x9953CF6,0x27628C,0x24012},{0xE84100C,0xD59EE09,0xF73FA14,0x9953CF6,0x27628C,0x24012}},{{0x1002002,0x800,0x0,0x0,0x0,0x0},{0x1002001,0x800,0x0,0x0,0x0,0x0},{0x1002001,0x800,0x0,0x0,0x0,0x0},{0x1002001,0x800,0x0,0x0,0x0,0x0}},{{0x801002,0x400,0x0,0x0,0x0,0x0},{0x2004002,0x1000,0x0,0x0,0x0,0x0},{0xE04000A,0xD59EA09,0xF73FA14,0x9953CF6,0x27628C,0x24012},{0x801002,0x400,0x0,0x0,0x0,0x0}}};
#endif

#if CHUNK==64

const int CURVE_Cof_I_BN158= 1;
const BIG_160_56 CURVE_Cof_BN158= {0x1L,0x0L,0x0L};
const int CURVE_B_I_BN158= 5;
const BIG_160_56 CURVE_B_BN158= {0x5L,0x0L,0x0L};
const BIG_160_56 CURVE_Order_BN158= {0xD59F209F04200DL,0x9953CF6F73FA14L,0x24012027628CL};
const BIG_160_56 CURVE_Gx_BN158= {0x72280AB04E012L,0x9953CF6FD3FB95L,0x24012027628CL};
const BIG_160_56 CURVE_Gy_BN158= {0x2L,0x0L,0x0L};
const BIG_160_56 CURVE_HTPC_BN158= {0x1L,0x0L,0x0L};

const BIG_160_56 CURVE_Bnx_BN158= {0x4000801001L,0x0L,0x0L};
const BIG_160_56 CURVE_Pxa_BN158= {0x3B2765033A5768L,0x1EECE2B3022922L,0x1EA35F882728L};
const BIG_160_56 CURVE_Pxb_BN158= {0x7B04ACE776A2F5L,0x5D05BA314F9D68L,0x23485611EB92L};
const BIG_160_56 CURVE_Pya_BN158= {0x69AB26E30CFE24L,0x1FB7A85F92C435L,0x1C952F906B6EL};
const BIG_160_56 CURVE_Pyb_BN158= {0x91017738E8609DL,0x8445B3BA0F3EE2L,0x23E289544ED8L};
const BIG_160_56 CURVE_W_BN158[2]= {{0x3182600A008003L,0x600180L,0x0L},{0x8001002001L,0x0L,0x0L}};
const BIG_160_56 CURVE_SB_BN158[2][2]= {{{0x3182E00B00A004L,0x600180L,0x0L},{0x8001002001L,0x0L,0x0L}},{{0x8001002001L,0x0L,0x0L},{0xA41CC09503A00AL,0x9953CF6F13F894L,0x24012027628CL}}};
const BIG_160_56 CURVE_WB_BN158[4]= {{0x10806002801000L,0x200080L,0x0L},{0xF907C026815005L,0x1202642519090L,0x30L},{0x7C84001380B003L,0x90132128C848L,0x18L},{0x1080E003803001L,0x200080L,0x0L}};
const BIG_160_56 CURVE_BB_BN158[4][4]= {{{0xD59EE09E84100DL,0x9953CF6F73FA14L,0x24012027628CL},{0xD59EE09E84100CL,0x9953CF6F73FA14L,0x24012027628CL},{0xD59EE09E84100CL,0x9953CF6F73FA14L,0x24012027628CL},{0x8001002002L,0x0L,0x0L}},{{0x8001002001L,0x0L,0x0L},{0xD59EE09E84100CL,0x9953CF6F73FA14L,0x24012027628CL},{0xD59EE09E84100DL,0x9953CF6F73FA14L,0x24012027628CL},{0xD59EE09E84100CL,0x9953CF6F73FA14L,0x24012027628CL}},{{0x8001002002L,0x0L,0x0L},{0x8001002001L,0x0L,0x0L},{0x8001002001L,0x0L,0x0L},{0x8001002001L,0x0L,0x0L}},{{0x4000801002L,0x0L,0x0L},{0x10002004002L,0x0L,0x0L},{0xD59EA09E04000AL,0x9953CF6F73FA14L,0x24012027628CL},{0x4000801002L,0x0L,0x0L}}};


#endif
