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
#include "fp_BLS48556.h"

/* Curve BLS48556 - Pairing friendly BLS48556 curve */

#if CHUNK==16

#error Not supported

#endif

#if CHUNK==32

// Base Bits= 29
const BIG_560_29 Modulus_BLS48556= {0x1CF6AC0B,0x17B7307F,0x19877E7B,0x12CE0134,0x14228402,0x1BD4C386,0x1DACBB04,0x40410D0,0x25A415,0x980B53E,0xDE6E250,0x15D9AAD6,0x5DA950,0x1029B7A,0x54AB351,0x14AD90CE,0x3729047,0x1FE7E2D9,0x145F610B,0x1F};
const BIG_560_29 ROI_BLS48556= {0x1CF6AC0A,0x17B7307F,0x19877E7B,0x12CE0134,0x14228402,0x1BD4C386,0x1DACBB04,0x40410D0,0x25A415,0x980B53E,0xDE6E250,0x15D9AAD6,0x5DA950,0x1029B7A,0x54AB351,0x14AD90CE,0x3729047,0x1FE7E2D9,0x145F610B,0x1F};
const BIG_560_29 R2modp_BLS48556= {0xD59D0FA,0x12F01FD0,0xDE8FD41,0x35AAEE1,0xB937F48,0x50700E8,0x1F50EFCE,0x1019B13C,0x3470A2F,0x11094115,0xF9FB72D,0x6AD10E2,0x1CFD9F8,0x44F4785,0x2B48793,0x1148ED3,0xF609E61,0x1EE34BC7,0x1735D29E,0x0};
const chunk MConst_BLS48556= 0x9DA805D;
const BIG_560_29 CRu_BLS48556= {0xCBBA429,0x1B273F3,0xD3DD160,0x19C61452,0x308093A,0x146E1E34,0xAE0E768,0x1185948,0x1B73BC2D,0x93D855C,0x1B1A639C,0x118C919B,0xFF04AE3,0xF1CCD77,0x91318E5,0x10644780,0x3A79F7,0x1BE77919,0x145F60F3,0x1F};
const BIG_560_29 Fra_BLS48556= {0x1325BF89,0x1311E7EC,0xCD0A56F,0x1A0FD46E,0xE83BCCA,0xCA97DD0,0x18D1D297,0x5F1E137,0x7AB9F2C,0x13FC255F,0x1C9DECEB,0x9DEF4A2,0x3C0F60B,0x1D9909E4,0x1FF27FF7,0x1DBF8208,0x89BB36C,0x40044E0,0x62E01EE,0x5};
const BIG_560_29 Frb_BLS48556= {0x1325BF89,0x1311E7EC,0xCD0A56F,0x1A0FD46E,0xE83BCCA,0xCA97DD0,0x18D1D297,0x5F1E137,0x7AB9F2C,0x13FC255F,0x1C9DECEB,0x9DEF4A2,0x3C0F60B,0x1D9909E4,0x1FF27FF7,0x1DBF8208,0x89BB36C,0x40044E0,0x62E01EE,0x5};
const BIG_560_29 SQRTm3_BLS48556= {0x1C809C48,0xBADB766,0xF42444,0xBE2770,0x11ED8E73,0xD0778E1,0x181513CC,0x1E2CA1BF,0x16C1D444,0x8FA557B,0x84DE4E8,0xD3F7861,0x1F82EC76,0x1D36FF74,0xCDB7E79,0xC1AFE32,0x1D0263A7,0x17E70F58,0x145F60DB,0x1F};
const BIG_560_29 TWK_BLS48556= {0x16F9937,0x9133D51,0xD89F92B,0x17A682C,0x16600368,0x1830F509,0x1531266E,0x159D972D,0x1C269C72,0x46E0687,0xCAA903,0x1EEF4D3A,0xED502F8,0x1046B2AB,0x1EC6EF4F,0xFD93805,0x1EEEDD57,0xD0AFF3F,0xC83E724,0x8};
#endif

#if CHUNK==64

// Base Bits= 58
const BIG_560_58 Modulus_BLS48556= {0x2F6E60FFCF6AC0BL,0x259C02699877E7BL,0x37A9870D4228402L,0x80821A1DACBB04L,0x13016A7C025A415L,0x2BB355ACDE6E250L,0x20536F405DA950L,0x295B219C54AB351L,0x3FCFC5B23729047L,0x3F45F610BL};
const BIG_560_58 ROI_BLS48556= {0x2F6E60FFCF6AC0AL,0x259C02699877E7BL,0x37A9870D4228402L,0x80821A1DACBB04L,0x13016A7C025A415L,0x2BB355ACDE6E250L,0x20536F405DA950L,0x295B219C54AB351L,0x3FCFC5B23729047L,0x3F45F610BL};
const BIG_560_58 R2modp_BLS48556= {0x25E03FA0D59D0FAL,0x6B55DC2DE8FD41L,0xA0E01D0B937F48L,0x20336279F50EFCEL,0x2212822A3470A2FL,0xD5A21C4F9FB72DL,0x89E8F0A1CFD9F8L,0x2291DA62B48793L,0x3DC6978EF609E61L,0x1735D29EL};
const chunk MConst_BLS48556= 0x21BFCBCA9DA805DL;
const BIG_560_58 CRu_BLS48556= {0x364E7E6CBBA429L,0x338C28A4D3DD160L,0x28DC3C68308093AL,0x230B290AE0E768L,0x127B0AB9B73BC2DL,0x23192337B1A639CL,0x1E399AEEFF04AE3L,0x20C88F0091318E5L,0x37CEF23203A79F7L,0x3F45F60F3L};
const BIG_560_58 Fra_BLS48556= {0x2623CFD9325BF89L,0x341FA8DCCD0A56FL,0x1952FBA0E83BCCAL,0xBE3C26F8D1D297L,0x27F84ABE7AB9F2CL,0x13BDE945C9DECEBL,0x3B3213C83C0F60BL,0x3B7F0411FF27FF7L,0x80089C089BB36CL,0xA62E01EEL};
const BIG_560_58 Frb_BLS48556= {0x2623CFD9325BF89L,0x341FA8DCCD0A56FL,0x1952FBA0E83BCCAL,0xBE3C26F8D1D297L,0x27F84ABE7AB9F2CL,0x13BDE945C9DECEBL,0x3B3213C83C0F60BL,0x3B7F0411FF27FF7L,0x80089C089BB36CL,0xA62E01EEL};
const BIG_560_58 SQRTm3_BLS48556= {0x175B6ECDC809C48L,0x17C4EE00F42444L,0x1A0EF1C31ED8E73L,0x3C59437F81513CCL,0x11F4AAF76C1D444L,0x1A7EF0C284DE4E8L,0x3A6DFEE9F82EC76L,0x1835FC64CDB7E79L,0x2FCE1EB1D0263A7L,0x3F45F60DBL};
const BIG_560_58 TWK_BLS48556= {0x12267AA216F9937L,0x2F4D058D89F92BL,0x3061EA136600368L,0x2B3B2E5B531266EL,0x8DC0D0FC269C72L,0x3DDE9A740CAA903L,0x208D6556ED502F8L,0x1FB2700BEC6EF4FL,0x1A15FE7FEEEDD57L,0x10C83E724L};
#endif