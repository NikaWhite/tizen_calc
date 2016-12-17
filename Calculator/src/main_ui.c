/*
 * main_ui.c
 *
 *  Created on: Dec 17, 2016
 *      Author: AcidLove
 */


#include "calculator.h"
#define EDJ_LAYOUT "base_layout.edj"

void _btn_clicked(void *data, Evas_Object *obj, void *event_info)
{
	Evas_Object *entry = (Evas_Object *)data;
	const char *text = elm_object_text_get(obj);
	const char *entry_text = elm_entry_entry_get(entry);
	Eina_Strbuf *buf = NULL;

	buf = eina_strbuf_new();
	eina_strbuf_free(buf);

}

Evas_Object *
base_ui(Evas_Object *parent)
{
	Evas_Object *layout = elm_layout_add(parent);
	elm_layout_file_set(layout, EDJ_LAYOUT, "main");

	Evas_Object *table = elm_table_add(layout);
	elm_layout_content_set(layout, "swallow.table", table);

	Evas_Object *btn = NULL;
	int counter = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			btn = elm_button_add(table);
			elm_object_text_set(button, atos(counter));
			counter++;
			elm_table_pack(table, btn, i, j, 0 ,0);
			evas_object_show(btn);
			evas_object_smart_callback_add(btn, "clicked", _btn_cliked, NULL);
		}
	}

	return layout;
}
