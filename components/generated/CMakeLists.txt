if(ESP_PLATFORM)
	file(GLOB_RECURSE SOURCES *.c ./images/*.c)
	idf_component_register(SRCS ${SOURCES}
						INCLUDE_DIRS . ./guider_customer_fonts ./guider_fonts ./images ../lvgl/src/font 
						REQUIRES lvgl)
else()
	message(FATAL ERROR "LVGL LV generated: ESP PLATFORM is not defined. Try reinstalling ESP-IDF.") 
endif()