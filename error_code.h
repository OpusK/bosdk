#ifndef BOSDK_ERROR_CODE_H_
#define BOSDK_ERROR_CODE_H_

#define BOSDK_OK                            0
#define BOSDK_ERR_MEMORY                    1
#define BOSDK_ERR_FULL                      2
#define BOSDK_ERR_EMPTY                     3
#define BOSDK_ERR_NULL                      4
#define BOSDK_ERR_INVAILD_INDEX             5

#define BOSDK_ERR_I2C_READ                  10
#define BOSDK_ERR_I2C_WRITE                 11

#define BOSDK_ERR_INVALID_CMD               100
#define BOSDK_ERR_INVALID_LENGTH            239
#define BOSDK_ERR_FLASH_INVALID_CHECK_SUM   240
#define BOSDK_ERR_FLASH_INVALID_TAG         241
#define BOSDK_ERR_INVALID_FW                242
#define BOSDK_ERR_FLASH_ADDR_ALIGN          243
#define BOSDK_ERR_FLASH_INVALID_ADDR        244
#define BOSDK_ERR_FLASH_ERROR               245
#define BOSDK_ERR_FLASH_BUSY                246
#define BOSDK_ERR_FLASH_ERR_TIMEOUT         247
#define BOSDK_ERR_FLASH_NOT_EMPTY           248
#define BOSDK_ERR_FLASH_WRITE               249
#define BOSDK_ERR_FLASH_READ                250
#define BOSDK_ERR_FLASH_ERASE               251
#define BOSDK_ERR_FLASH_PACKET_SIZE         252
#define BOSDK_ERR_FLASH_SIZE                253
#define BOSDK_ERR_FLASH_CRC                 254


#define BOSDK_ERR_MEMORY_ERASE_LENGTH       300
#define BOSDK_ERR_MEMORY_ERASE_ALIGN        301
#define BOSDK_ERR_MEMORY_ERASE_PARAM        302
#define BOSDK_ERR_MEMORY_ERASE_RANGE        304
#define BOSDK_ERR_MEMORY_READ_LENGTH        305
#define BOSDK_ERR_MEMORY_READ_PARAM         306
#define BOSDK_ERR_MEMORY_READ_RANGE         307
#define BOSDK_ERR_MEMORY_WRITE_LENGTH       308
#define BOSDK_ERR_MEMORY_WRITE_PARAM        309
#define BOSDK_ERR_MEMORY_WRITE_ALIGN        310
#define BOSDK_ERR_MEMORY_WRITE_RANGE        311


#define BOSDK_ERR_DXL_ERROR                 400

#define BOSDK_ERR_RPI_ERROR                 500

#define BOSDK_ERR_DXL_ERROR_RESP            700


#define BOSDK_ERR_DXL_NOT_OPEN              1000
#define BOSDK_ERR_DXL_WRITE_BUFFER          1001
#define BOSDK_ERR_DXL_NOT_FOUND             1002
#define BOSDK_ERR_DXL_WRTIE_USB             1003
#define BOSDK_ERR_DXL_WRTIE_UART            1004
#define BOSDK_ERR_DXL_WRTIE_BLE             1005
#define BOSDK_ERR_DXL_WRTIE_MOTOR           1006


#define BOSDK_ERR_MOTION_OVER_STEP          1100
#define BOSDK_ERR_MOTION_OVER_PAGE          1101
#define BOSDK_ERR_MOTION_WRITE_BUFFER       1102
#define BOSDK_ERR_MOTION_FAIL_START         1103
#define BOSDK_ERR_MOTION_OVER_GOAL          1104
#define BOSDK_ERR_MOTION_WAIT_TIMEOUT       1105
#define BOSDK_ERR_MOTION_PAGE_VALID         1106

#define BOSDK_ERR_TASK_RANGE                1200
#define BOSDK_ERR_TASK_INVAILD_PARAM        1201
#define BOSDK_ERR_TASK_UNKNOWN_TYPE         1202
#define BOSDK_ERR_TASK_CONST_TYPE           1203
#define BOSDK_ERR_TASK_VAR_LENGTH           1204
#define BOSDK_ERR_TASK_VAR_TYPE             1205
#define BOSDK_ERR_TASK_INVAILD_TYPE         1206
#define BOSDK_ERR_TASK_PUT_INVAILD_TYPE     1207
#define BOSDK_ERR_TASK_INVAILD_OPERATOR     1208
#define BOSDK_ERR_TASK_ACC_LENGTH           1209
#define BOSDK_ERR_TASK_STACK_OVER           1210
#define BOSDK_ERR_TASK_STACK_UNDER          1211
#define BOSDK_ERR_TASK_LENGTH_OVER          1212
#define BOSDK_ERR_TASK_CONST_ID_CONST_ADDR_TYPE   1213
#define BOSDK_ERR_TASK_INVAILD_SENTENCE     1214
#define BOSDK_ERR_TASK_INVAILD_COMPUTE      1215


#define BOSDK_ERR_ETHERNET                  4000
#define BOSDK_ERR_ETHERNET_JOIN_GROUP       4040
#define BOSDK_ERR_ETHERNET_LEAVE_GROUP      4050



#endif /* BOSDK_ERROR_CODE_H_ */
