set(include_dirs  "."
                  "F:/espidf/esp/esp-idf/components/nvs_flash/include"
                  "F:/espidf/esp/esp-idf/components/nvs_flash"
                  "F:/espidf/esp/esp-idf/components/json/cJSON"
                  
                  "F:/espidf/esp/esp-idf/components/spi_flash/include"

)

idf_component_register(SRCS "custom.c" 
                            "lvgl_init.c" 
                            "blink.c" 
                            "../components/lvgl/examples/get_started/lv_example_get_started_1.c"
                            "src/board_gpio.c"
                            "src/board_mfrc522.c"
                            "src/board_spi.c"
                            "src/user_nfc.c"
                            
                            
                    INCLUDE_DIRS "."
                    			 "../components/generated"
                                 "../components/lvgl_esp32_drivers"
                                 "./include"
                                 "${include_dirs}"
                    REQUIRES mqtt
                             generated)
