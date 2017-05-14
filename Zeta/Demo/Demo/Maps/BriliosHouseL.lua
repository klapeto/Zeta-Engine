return {
  version = "1.1",
  luaversion = "5.1",
  tiledversion = "2016.03.09",
  orientation = "orthogonal",
  renderorder = "right-down",
  width = 15,
  height = 15,
  tilewidth = 64,
  tileheight = 64,
  nextobjectid = 18,
  properties = {
    ["Layer Priority"] = "Floor,Walls,WallPaper,Decoration1,Decoration2,_OBJ_,Decoration3",
    ["Script"] = "Scripts/Hera_Isle.lua"
  },
  tilesets = {
    {
      name = "LPC",
      firstgid = 1,
      filename = "Tilesets/LPC.tsx",
      tilewidth = 64,
      tileheight = 64,
      spacing = 0,
      margin = 0,
      image = "Tilesets/tileset.png",
      imagewidth = 2048,
      imageheight = 2048,
      tileoffset = {
        x = 0,
        y = 0
      },
      properties = {},
      terrains = {
        {
          name = "Brick_Wall",
          tile = 705,
          properties = {}
        },
        {
          name = "Sewer_Wall",
          tile = 493,
          properties = {}
        },
        {
          name = "Cliff",
          tile = 757,
          properties = {}
        },
        {
          name = "Grass_Lake",
          tile = 932,
          properties = {}
        },
        {
          name = "Sewer_Water",
          tile = 935,
          properties = {}
        },
        {
          name = "Lava_Lake",
          tile = 956,
          properties = {}
        },
        {
          name = "Lake",
          tile = 828,
          properties = {}
        },
        {
          name = "Hole",
          tile = 316,
          properties = {}
        },
        {
          name = "Dirt",
          tile = 313,
          properties = {}
        },
        {
          name = "Dark_Dirt",
          tile = 124,
          properties = {}
        },
        {
          name = "Grass",
          tile = 121,
          properties = {}
        }
      },
      tilecount = 1024,
      tiles = {
        {
          id = 25,
          terrain = { 10, 10, 10, -1 }
        },
        {
          id = 26,
          terrain = { 10, 10, -1, 10 }
        },
        {
          id = 28,
          terrain = { 9, 9, 9, -1 }
        },
        {
          id = 29,
          terrain = { 9, 9, -1, 9 }
        },
        {
          id = 57,
          terrain = { 10, -1, 10, 10 }
        },
        {
          id = 58,
          terrain = { -1, 10, 10, 10 }
        },
        {
          id = 60,
          terrain = { 9, -1, 9, 9 }
        },
        {
          id = 61,
          terrain = { -1, 9, 9, 9 }
        },
        {
          id = 64,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 65,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 66,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 71,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 88,
          terrain = { -1, -1, -1, 10 }
        },
        {
          id = 89,
          terrain = { -1, -1, 10, 10 }
        },
        {
          id = 90,
          terrain = { -1, -1, 10, -1 }
        },
        {
          id = 91,
          terrain = { -1, -1, -1, 9 }
        },
        {
          id = 92,
          terrain = { -1, -1, 9, 9 }
        },
        {
          id = 93,
          terrain = { -1, -1, 9, -1 }
        },
        {
          id = 96,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 97,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 98,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 120,
          terrain = { -1, 10, -1, 10 }
        },
        {
          id = 121,
          terrain = { 10, 10, 10, 10 }
        },
        {
          id = 122,
          terrain = { 10, -1, 10, -1 }
        },
        {
          id = 123,
          terrain = { -1, 9, -1, 9 }
        },
        {
          id = 124,
          terrain = { 9, 9, 9, 9 }
        },
        {
          id = 125,
          terrain = { 9, -1, 9, -1 }
        },
        {
          id = 129,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 130,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 131,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 132,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 133,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 134,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 152,
          terrain = { -1, 10, -1, -1 }
        },
        {
          id = 153,
          terrain = { 10, 10, -1, -1 }
        },
        {
          id = 154,
          terrain = { 10, -1, -1, -1 }
        },
        {
          id = 155,
          terrain = { -1, 9, -1, -1 }
        },
        {
          id = 156,
          terrain = { 9, 9, -1, -1 }
        },
        {
          id = 157,
          terrain = { 9, -1, -1, -1 }
        },
        {
          id = 161,
          properties = {
            ["Collision"] = "4"
          }
        },
        {
          id = 162,
          properties = {
            ["Collision"] = "8"
          }
        },
        {
          id = 163,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 164,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 165,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 166,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 184,
          terrain = { 10, 10, 10, 10 }
        },
        {
          id = 185,
          terrain = { 10, 10, 10, 10 }
        },
        {
          id = 186,
          terrain = { 10, 10, 10, 10 }
        },
        {
          id = 187,
          terrain = { 9, 9, 9, 9 }
        },
        {
          id = 188,
          terrain = { 9, 9, 9, 9 }
        },
        {
          id = 189,
          terrain = { 9, 9, 9, 9 }
        },
        {
          id = 193,
          properties = {
            ["Collision"] = "4"
          }
        },
        {
          id = 194,
          properties = {
            ["Collision"] = "8"
          }
        },
        {
          id = 195,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 196,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 197,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 198,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 217,
          terrain = { 8, 8, 8, -1 }
        },
        {
          id = 218,
          terrain = { 8, 8, -1, 8 }
        },
        {
          id = 220,
          properties = {
            ["Collision"] = "7"
          },
          terrain = { 7, 7, 7, -1 }
        },
        {
          id = 221,
          properties = {
            ["Collision"] = "11"
          },
          terrain = { 7, 7, -1, 7 }
        },
        {
          id = 227,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 228,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 229,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 230,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 249,
          terrain = { 8, -1, 8, 8 }
        },
        {
          id = 250,
          terrain = { -1, 8, 8, 8 }
        },
        {
          id = 252,
          properties = {
            ["Collision"] = "13"
          },
          terrain = { 7, -1, 7, 7 }
        },
        {
          id = 253,
          properties = {
            ["Collision"] = "14"
          },
          terrain = { -1, 7, 7, 7 }
        },
        {
          id = 267,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 269,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 270,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 280,
          terrain = { -1, -1, -1, 8 }
        },
        {
          id = 281,
          terrain = { -1, -1, 8, 8 }
        },
        {
          id = 282,
          terrain = { -1, -1, 8, -1 }
        },
        {
          id = 283,
          properties = {
            ["Collision"] = "1"
          },
          terrain = { -1, -1, -1, 7 }
        },
        {
          id = 284,
          properties = {
            ["Collision"] = "3"
          },
          terrain = { -1, -1, 7, 7 }
        },
        {
          id = 285,
          properties = {
            ["Collision"] = "2"
          },
          terrain = { -1, -1, 7, -1 }
        },
        {
          id = 301,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 302,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 303,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 312,
          terrain = { -1, 8, -1, 8 }
        },
        {
          id = 313,
          terrain = { 8, 8, 8, 8 }
        },
        {
          id = 314,
          terrain = { 8, -1, 8, -1 }
        },
        {
          id = 315,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, 7, -1, 7 }
        },
        {
          id = 316,
          terrain = { 7, 7, 7, 7 }
        },
        {
          id = 317,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 7, -1, 7, -1 }
        },
        {
          id = 320,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 321,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 322,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 323,
          properties = {
            [""] = ""
          }
        },
        {
          id = 334,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 335,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 344,
          terrain = { -1, 8, -1, -1 }
        },
        {
          id = 345,
          terrain = { 8, 8, -1, -1 }
        },
        {
          id = 346,
          terrain = { 8, -1, -1, -1 }
        },
        {
          id = 347,
          properties = {
            ["Collision"] = "4"
          },
          terrain = { -1, 7, -1, -1 }
        },
        {
          id = 348,
          properties = {
            ["Collision"] = "12"
          },
          terrain = { 7, 7, -1, -1 }
        },
        {
          id = 349,
          properties = {
            ["Collision"] = "8"
          },
          terrain = { 7, -1, -1, -1 }
        },
        {
          id = 352,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 353,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 354,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 355,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 356,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 358,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 365,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 366,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 376,
          terrain = { 8, 8, 8, 8 }
        },
        {
          id = 377,
          terrain = { 8, 8, 8, 8 }
        },
        {
          id = 378,
          terrain = { 8, 8, 8, 8 }
        },
        {
          id = 379,
          terrain = { 7, 7, 7, 7 }
        },
        {
          id = 380,
          terrain = { 7, 7, 7, 7 }
        },
        {
          id = 381,
          terrain = { 7, 7, 7, 7 }
        },
        {
          id = 384,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 385,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 386,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 387,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 388,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 391,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 397,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 398,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 418,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 419,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 420,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 421,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 422,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 423,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 424,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 425,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 426,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 448,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 449,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 452,
          properties = {
            ["Collision"] = "0"
          }
        },
        {
          id = 453,
          properties = {
            ["Collision"] = "0"
          }
        },
        {
          id = 454,
          properties = {
            ["Collision"] = "0"
          }
        },
        {
          id = 455,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 460,
          terrain = { -1, -1, -1, 1 }
        },
        {
          id = 461,
          terrain = { -1, -1, 1, 1 }
        },
        {
          id = 462,
          terrain = { -1, -1, 1, -1 }
        },
        {
          id = 480,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 481,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 482,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 483,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 484,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 485,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 486,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 487,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 492,
          terrain = { -1, 1, -1, 1 }
        },
        {
          id = 493,
          terrain = { 1, 1, 1, 1 }
        },
        {
          id = 494,
          terrain = { 1, -1, 1, -1 }
        },
        {
          id = 512,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 513,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 514,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 515,
          properties = {
            ["Collsion"] = "15"
          }
        },
        {
          id = 516,
          properties = {
            ["Collision"] = "4"
          }
        },
        {
          id = 517,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 518,
          properties = {
            ["Collision"] = "8"
          }
        },
        {
          id = 519,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 524,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, 1, -1, -1 }
        },
        {
          id = 525,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { 1, 1, -1, -1 }
        },
        {
          id = 526,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { 1, -1, -1, -1 }
        },
        {
          id = 531,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 534,
          properties = {
            ["Collision"] = "13"
          }
        },
        {
          id = 535,
          properties = {
            ["Collision"] = "14"
          }
        },
        {
          id = 546,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 554,
          properties = {
            ["Collision"] = "11"
          }
        },
        {
          id = 555,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 566,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 567,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 578,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 579,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 580,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 584,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 585,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 586,
          properties = {
            ["Collision"] = "14"
          }
        },
        {
          id = 587,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 618,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 619,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 634,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 637,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 648,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 649,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 650,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 651,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 666,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 669,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 672,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, -1, -1, 0 }
        },
        {
          id = 673,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, -1, 0, 0 }
        },
        {
          id = 674,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, -1, 0, -1 }
        },
        {
          id = 704,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, 0, -1, 0 }
        },
        {
          id = 705,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { 0, 0, 0, 0 }
        },
        {
          id = 706,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { 0, -1, 0, -1 }
        },
        {
          id = 719,
          properties = {
            ["Collision"] = "1"
          }
        },
        {
          id = 720,
          properties = {
            ["Collision"] = "3"
          }
        },
        {
          id = 721,
          properties = {
            ["Collision"] = "2"
          }
        },
        {
          id = 724,
          properties = {
            ["Collision"] = "1"
          },
          terrain = { -1, -1, -1, 2 }
        },
        {
          id = 725,
          properties = {
            ["Collision"] = "3"
          },
          terrain = { -1, -1, 2, 2 }
        },
        {
          id = 726,
          properties = {
            ["Collision"] = "2"
          },
          terrain = { -1, -1, 2, -1 }
        },
        {
          id = 727,
          properties = {
            ["Collision"] = "8"
          },
          terrain = { -1, 2, 2, 2 }
        },
        {
          id = 728,
          properties = {
            ["Collision"] = "4"
          },
          terrain = { 2, -1, 2, 2 }
        },
        {
          id = 732,
          properties = {
            ["Collision"] = "7"
          },
          terrain = { 6, 6, 6, -1 }
        },
        {
          id = 733,
          properties = {
            ["Collision"] = "11"
          },
          terrain = { 6, 6, -1, 6 }
        },
        {
          id = 736,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, 0, -1, -1 }
        },
        {
          id = 737,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { 0, 0, -1, -1 }
        },
        {
          id = 738,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { 0, -1, -1, -1 }
        },
        {
          id = 751,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 753,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 756,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, 2, -1, 2 }
        },
        {
          id = 757,
          terrain = { 2, 2, 2, 2 }
        },
        {
          id = 758,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 2, -1, 2, -1 }
        },
        {
          id = 759,
          properties = {
            ["2"] = "10"
          },
          terrain = { 2, 2, -1, 2 }
        },
        {
          id = 760,
          properties = {
            ["Collision"] = "1"
          },
          terrain = { 2, 2, 2, -1 }
        },
        {
          id = 764,
          properties = {
            ["Collision"] = "13"
          },
          terrain = { 6, -1, 6, 6 }
        },
        {
          id = 765,
          properties = {
            ["Collision"] = "14"
          },
          terrain = { -1, 6, 6, 6 }
        },
        {
          id = 783,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 784,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 785,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 788,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, 2, -1, -1 }
        },
        {
          id = 789,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { 2, 2, -1, -1 }
        },
        {
          id = 790,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 2, -1, -1, -1 }
        },
        {
          id = 791,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 792,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 795,
          properties = {
            ["Collision"] = "1"
          },
          terrain = { -1, -1, -1, 6 }
        },
        {
          id = 796,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, -1, 6, 6 }
        },
        {
          id = 797,
          properties = {
            ["Collision"] = "2"
          },
          terrain = { -1, -1, 6, -1 }
        },
        {
          id = 815,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 816,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 817,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 820,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 821,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 822,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 823,
          properties = {
            ["Collision"] = "5"
          }
        },
        {
          id = 824,
          properties = {
            ["Collision"] = "10"
          }
        },
        {
          id = 827,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, 6, -1, 6 }
        },
        {
          id = 828,
          terrain = { 6, 6, 6, 6 }
        },
        {
          id = 829,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 6, -1, 6, -1 }
        },
        {
          id = 859,
          properties = {
            ["Collision"] = "4"
          },
          terrain = { -1, 6, -1, -1 }
        },
        {
          id = 860,
          properties = {
            ["Collision"] = "12"
          },
          terrain = { 6, 6, -1, -1 }
        },
        {
          id = 861,
          properties = {
            ["Collision"] = "8"
          },
          terrain = { 6, -1, -1, -1 }
        },
        {
          id = 880,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 881,
          properties = {
            ["Collision"] = "12"
          }
        },
        {
          id = 891,
          terrain = { 6, 6, 6, 6 }
        },
        {
          id = 892,
          terrain = { 6, 6, 6, 6 }
        },
        {
          id = 893,
          terrain = { 6, 6, 6, 6 }
        },
        {
          id = 897,
          properties = {
            ["Collision"] = "11"
          },
          terrain = { 3, 3, 3, -1 }
        },
        {
          id = 898,
          properties = {
            ["Collision"] = "11"
          },
          terrain = { 3, 3, -1, 3 }
        },
        {
          id = 899,
          properties = {
            ["Collision"] = "1"
          },
          terrain = { -1, -1, -1, 3 }
        },
        {
          id = 900,
          properties = {
            ["Collision"] = "3"
          },
          terrain = { -1, -1, 3, 3 }
        },
        {
          id = 901,
          properties = {
            ["Collision"] = "2"
          },
          terrain = { -1, -1, 3, -1 }
        },
        {
          id = 902,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, -1, -1, 4 }
        },
        {
          id = 903,
          terrain = { -1, -1, 4, 4 }
        },
        {
          id = 904,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { -1, -1, 4, -1 }
        },
        {
          id = 923,
          properties = {
            ["Collision"] = "1"
          },
          terrain = { -1, -1, -1, 5 }
        },
        {
          id = 924,
          properties = {
            ["Collision"] = "15"
          },
          terrain = { -1, -1, 5, 5 }
        },
        {
          id = 925,
          properties = {
            ["Collision"] = "2"
          },
          terrain = { -1, -1, 5, -1 }
        },
        {
          id = 929,
          properties = {
            ["Collision"] = "13"
          },
          terrain = { 3, -1, 3, 3 }
        },
        {
          id = 930,
          properties = {
            ["Collision"] = "14"
          },
          terrain = { -1, 3, 3, 3 }
        },
        {
          id = 931,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, 3, -1, 3 }
        },
        {
          id = 932,
          terrain = { 3, 3, 3, 3 }
        },
        {
          id = 933,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 3, -1, 3, -1 }
        },
        {
          id = 934,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, 4, -1, 4 }
        },
        {
          id = 935,
          terrain = { 4, 4, 4, 4 }
        },
        {
          id = 936,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 4, -1, 4, -1 }
        },
        {
          id = 953,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 955,
          terrain = { -1, 5, -1, 5 }
        },
        {
          id = 956,
          terrain = { 5, 5, 5, 5 }
        },
        {
          id = 957,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 5, -1, 5, -1 }
        },
        {
          id = 961,
          properties = {
            ["Collision"] = "14"
          },
          terrain = { 4, 4, 4, -1 }
        },
        {
          id = 962,
          properties = {
            ["Collision"] = "13"
          },
          terrain = { 4, 4, -1, 4 }
        },
        {
          id = 963,
          properties = {
            ["Collision"] = "4"
          },
          terrain = { -1, 3, -1, -1 }
        },
        {
          id = 964,
          properties = {
            ["Collision"] = "12"
          },
          terrain = { 3, 3, -1, -1 }
        },
        {
          id = 965,
          properties = {
            ["Collision"] = "8"
          },
          terrain = { 3, -1, -1, -1 }
        },
        {
          id = 966,
          properties = {
            ["Collision"] = "5"
          },
          terrain = { -1, 4, -1, -1 }
        },
        {
          id = 967,
          properties = {
            ["Collision"] = "12"
          },
          terrain = { 4, 4, -1, -1 }
        },
        {
          id = 968,
          properties = {
            ["Collision"] = "10"
          },
          terrain = { 4, -1, -1, -1 }
        },
        {
          id = 973,
          properties = {
            ["Collision"] = "7"
          },
          terrain = { 5, 5, 5, -1 }
        },
        {
          id = 974,
          properties = {
            ["Collision"] = "11"
          },
          terrain = { 5, 5, -1, 5 }
        },
        {
          id = 975,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 976,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 977,
          properties = {
            ["Collision"] = "15"
          }
        },
        {
          id = 987,
          properties = {
            ["Collision"] = "4"
          },
          terrain = { -1, 5, -1, -1 }
        },
        {
          id = 988,
          properties = {
            ["Collision"] = "12"
          },
          terrain = { 5, 5, -1, -1 }
        },
        {
          id = 989,
          properties = {
            ["Collision"] = "8"
          },
          terrain = { 5, -1, -1, -1 }
        },
        {
          id = 993,
          properties = {
            ["Collision"] = "11"
          },
          terrain = { 4, -1, 4, 4 }
        },
        {
          id = 994,
          properties = {
            ["Collision"] = "7"
          },
          terrain = { -1, 4, 4, 4 }
        },
        {
          id = 995,
          terrain = { 3, 3, 3, 3 }
        },
        {
          id = 996,
          terrain = { 3, 3, 3, 3 }
        },
        {
          id = 997,
          terrain = { 3, 3, 3, 3 }
        },
        {
          id = 998,
          terrain = { 4, 4, 4, 4 }
        },
        {
          id = 999,
          terrain = { 4, 4, 4, 4 }
        },
        {
          id = 1000,
          terrain = { 4, 4, 4, 4 }
        },
        {
          id = 1005,
          properties = {
            ["Collision"] = "13"
          },
          terrain = { 5, -1, 5, 5 }
        },
        {
          id = 1006,
          properties = {
            ["Collision"] = "14"
          },
          terrain = { -1, 5, 5, 5 }
        },
        {
          id = 1019,
          terrain = { 5, 5, 5, 5 }
        },
        {
          id = 1020,
          terrain = { 5, 5, 5, 5 }
        },
        {
          id = 1021,
          terrain = { 5, 5, 5, 5 }
        }
      }
    }
  },
  layers = {
    {
      type = "tilelayer",
      name = "Floor",
      x = 0,
      y = 0,
      width = 15,
      height = 15,
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      encoding = "base64",
      compression = "zlib",
      data = "eJxjYMAPGnFgfOqIBaSoJdZd+PCo3qGjFxegJM0MVgAAp7E59A=="
    },
    {
      type = "tilelayer",
      name = "Walls",
      x = 0,
      y = 0,
      width = 15,
      height = 15,
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      encoding = "base64",
      compression = "zlib",
      data = "eJxrZWBgYARiJhIwMxC3AXETECsCsRIJWBmIm6F6HYHYiQTsjKSXHDCqd2joPQTESVhwMlRNIg75w2TaOdAAAOKPFok="
    },
    {
      type = "tilelayer",
      name = "WallPaper",
      x = 0,
      y = 0,
      width = 15,
      height = 15,
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      encoding = "base64",
      compression = "zlib",
      data = "eJxjYICAhSTSyOAgiTQyeEgiPQpGwXADALcSDZM="
    },
    {
      type = "tilelayer",
      name = "Decoration1",
      x = 0,
      y = 0,
      width = 15,
      height = 15,
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      encoding = "base64",
      compression = "zlib",
      data = "eJxjYMANPKG0GyMqHxnkAzEfEHMDcTsjQjwTSqcxovKRQT8Q6wGxNpp4J5RuY0TlI4P1QOwHxN443L6MEYcECcALixkBjBCsT8D8LCrYT2+gysTA8Bjo7idkup0ZqJ+FibpuGgkAADnNCxY="
    },
    {
      type = "tilelayer",
      name = "Decoration2",
      x = 0,
      y = 0,
      width = 15,
      height = 15,
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      encoding = "base64",
      compression = "zlib",
      data = "eJxjYKAucGKiTJ4WIJsJgmkJnjIyMDwD4ueMpOtlBbqNDYjZ0dzoTCU3U8ucUUAbAAAOkAS6"
    },
    {
      type = "tilelayer",
      name = "Decoration3",
      x = 0,
      y = 0,
      width = 15,
      height = 15,
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      encoding = "base64",
      compression = "zlib",
      data = "eJxjYBh5wB+I3RkH2hWjYBRAAACFYgCY"
    },
    {
      type = "objectgroup",
      name = "NPCS",
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      objects = {
        {
          id = 1,
          name = "Μαρία",
          type = "Npc",
          shape = "rectangle",
          x = 349,
          y = 352,
          width = 52,
          height = 28,
          rotation = 0,
          visible = true,
          properties = {
            ["Module"] = "Demo.NPCS.Maria_Briliou"
          }
        },
        {
          id = 2,
          name = "Κότα",
          type = "Npc",
          shape = "rectangle",
          x = 259,
          y = 513,
          width = 44,
          height = 20,
          rotation = 0,
          visible = true,
          properties = {
            ["Module"] = "Demo.Enemies.Chicken"
          }
        },
        {
          id = 3,
          name = "Κότα",
          type = "Npc",
          shape = "rectangle",
          x = 642,
          y = 513,
          width = 44,
          height = 20,
          rotation = 0,
          visible = true,
          properties = {
            ["Module"] = "Demo.Enemies.Chicken"
          }
        }
      }
    },
    {
      type = "objectgroup",
      name = "StaticObjects",
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      objects = {
        {
          id = 4,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 768,
          y = 512,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 451,
          visible = true,
          properties = {}
        },
        {
          id = 5,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 832,
          y = 512,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 452,
          visible = true,
          properties = {}
        },
        {
          id = 6,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 512,
          y = 320,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 454,
          visible = true,
          properties = {}
        },
        {
          id = 7,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 448,
          y = 320,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 453,
          visible = true,
          properties = {}
        },
        {
          id = 8,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 576,
          y = 320,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 455,
          visible = true,
          properties = {}
        },
        {
          id = 9,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 832,
          y = 384,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 547,
          visible = true,
          properties = {}
        },
        {
          id = 10,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 192,
          y = 320,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 271,
          visible = true,
          properties = {}
        },
        {
          id = 11,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 128,
          y = 320,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 268,
          visible = true,
          properties = {}
        },
        {
          id = 12,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 64,
          y = 320,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 270,
          visible = true,
          properties = {}
        },
        {
          id = 13,
          name = "",
          type = "Static",
          shape = "rectangle",
          x = 64,
          y = 512,
          width = 64,
          height = 64,
          rotation = 0,
          gid = 547,
          visible = true,
          properties = {}
        }
      }
    },
    {
      type = "objectgroup",
      name = "TouchFields",
      visible = true,
      opacity = 1,
      offsetx = 0,
      offsety = 0,
      properties = {},
      objects = {
        {
          id = 14,
          name = "Teleport",
          type = "InteractField",
          shape = "rectangle",
          x = 448,
          y = 704,
          width = 64,
          height = 64,
          rotation = 0,
          visible = true,
          properties = {
            ["onCollision"] = "require(\"Demo.Operations\").ChangeMap(require(\"Demo.Maps.FineForest\"))"
          }
        },
        {
          id = 15,
          name = "Πιάτα",
          type = "InteractField",
          shape = "rectangle",
          x = 134,
          y = 281,
          width = 46,
          height = 23,
          rotation = 0,
          visible = true,
          properties = {
            ["Collidable"] = "0",
            ["onClick"] = "require('Demo.Operations').InteractAction(function(Player,Object) require('Demo.Operations').Notify(\"Τα πιάτα είναι ίδη πλυμένα... Δεν χρειάζετε να κάνω κάτι.\") Player:face(Object) end,80,...)"
          }
        },
        {
          id = 16,
          name = "Σενούκια",
          type = "InteractField",
          shape = "rectangle",
          x = 782,
          y = 204,
          width = 108,
          height = 48,
          rotation = 0,
          visible = true,
          properties = {
            ["onClick"] = "require('Demo.Operations').InteractAction(function(Player,Object) require('Demo.Operations').Notify(\"Καλύτερα να μην πειράξω τα πράγματα των ανθρώπων.\") Player:face(Object)  end,200,...)"
          }
        }
      }
    }
  }
}
