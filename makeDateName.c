#include "ext.h"							// standard Max include, always required
#include "ext_obex.h"						// required for new style Max object
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>


typedef struct _makeDateName{
    t_object s_obj;
    void *m_outlet1;
    void *m_outlet2;
    void *m_outlet3;
    void *m_outlet4;
    void *m_outlet5;
    void *m_outlet6;
    void *m_outlet7;
    void *m_outlet8;
    void *m_outlet9;
    void *m_outlet10;
    void *m_outlet11;
    void *m_outlet12;
    void *m_outlet13;
    void *m_outlet14;
    void *m_outlet15;
    void *m_outlet16;
    void *m_outlet17;
}t_makeDateName;

static t_class *s_makeDateName_class; // global pointer to our class definition that is setup in ext_main()

void *makeDateName_new();
void makeDateName_int(t_makeDateName *x, long n);
//void makeDateName_bang(t_makeDateName *x);
//void makeDateName_float(t_makeDateName *x, double f);
t_symbol *o_name[16];


void ext_main(void *r)
{
    t_class *c;
    c = class_new("makeDateName", (method)makeDateName_new, (method)NULL, sizeof(t_makeDateName), 0L, 0);
    class_addmethod(c, (method)makeDateName_int, "int", A_LONG, 0);
    //class_addmethod(c, (method)makeDateName_bang, "bang", 0);
    //class_addmethod(c, (method)makeDateName_float, "float", A_FLOAT, 0);
    class_register(CLASS_BOX, c);
    s_makeDateName_class = c;
}

void *makeDateName_new()
{
    t_makeDateName *x = (t_makeDateName *)object_alloc(s_makeDateName_class);
    x->m_outlet17 = outlet_new((t_object *)x, NULL);
    x->m_outlet16 = outlet_new((t_object *)x, NULL);
    x->m_outlet15 = outlet_new((t_object *)x, NULL);
    x->m_outlet14 = outlet_new((t_object *)x, NULL);
    x->m_outlet13 = outlet_new((t_object *)x, NULL);
    x->m_outlet12 = outlet_new((t_object *)x, NULL);
    x->m_outlet11 = outlet_new((t_object *)x, NULL);
    x->m_outlet10 = outlet_new((t_object *)x, NULL);
    x->m_outlet9 = outlet_new((t_object *)x, NULL);
    x->m_outlet8 = outlet_new((t_object *)x, NULL);
    x->m_outlet7 = outlet_new((t_object *)x, NULL);
    x->m_outlet6 = outlet_new((t_object *)x, NULL);
    x->m_outlet5 = outlet_new((t_object *)x, NULL);
    x->m_outlet4 = outlet_new((t_object *)x, NULL);
    x->m_outlet3 = outlet_new((t_object *)x, NULL);
    x->m_outlet2 = outlet_new((t_object *)x, NULL);
    x->m_outlet1 = outlet_new((t_object *)x, NULL);
    
    return x;
}

void makeDateName_int(t_makeDateName *x, long n)
{
    char *home_path;
    char path[255];
    char date[64];
    char dir_name[24] = "/Desktop/SPWN_multiRec_";

    
    //post("%s\n", dir_name);
    home_path = getenv("HOME");
    //post("%s\n", home_path);
    //post("%d", sizeof(home_path));
    unsigned i;
    for(i=0; i<255; i++){
        path[i] = home_path[i];
    };
    //post("%s", path);
    
    strncat(path, dir_name, 127);
    
    time_t t = time(NULL);
    strftime(date, sizeof(date), "%y%m%d%H%M%S", localtime(&t));
    strncat(path, date, 64);
    
    
    post("%s\n", path);
    post("mkdir()実行 : %d\n", mkdir(path, 0777));
    
    int nth;
    char num[255];
    char p[255];
    for(nth=0; nth < 16; i++){
        strcpy(p, path);
        char track_name[255] = "/track";
        nth += 1;
        snprintf(num, 12, "%d", nth);
        //post("%s", num);
        strncat(track_name, num, 255);
        strncat(track_name, ".wav", 255);
        //post("%s", track_name);
        strncat(p, track_name, 255);
        o_name[nth-1] = gensym(p);
        track_name[0] = '\0';
        p[0] = '\0';
    };
    

    
    //outlet_anything(x->m_outlet1, gensym("bang"), 0, NIL);
    outlet_anything(x->m_outlet1, o_name[0], 0, NIL);
    outlet_anything(x->m_outlet2, o_name[1], 0, NIL);
    outlet_anything(x->m_outlet3, o_name[2], 0, NIL);
    outlet_anything(x->m_outlet4, o_name[3], 0, NIL);
    outlet_anything(x->m_outlet5, o_name[4], 0, NIL);
    outlet_anything(x->m_outlet6, o_name[5], 0, NIL);
    outlet_anything(x->m_outlet7, o_name[6], 0, NIL);
    outlet_anything(x->m_outlet8, o_name[7], 0, NIL);
    outlet_anything(x->m_outlet9, o_name[8], 0, NIL);
    outlet_anything(x->m_outlet10, o_name[9], 0, NIL);
    outlet_anything(x->m_outlet11, o_name[10], 0, NIL);
    outlet_anything(x->m_outlet12, o_name[11], 0, NIL);
    outlet_anything(x->m_outlet13, o_name[12], 0, NIL);
    outlet_anything(x->m_outlet14, o_name[13], 0, NIL);
    outlet_anything(x->m_outlet15, o_name[14], 0, NIL);
    outlet_anything(x->m_outlet16, o_name[15], 0, NIL);
    
    
    
    
    date[0] = '\0';
    dir_name[0] = '\0';
    path[0] = '\0';
    
    //notice finish
     outlet_bang(x->m_outlet17);
}

//void makeDateName_bang(t_makeDateName *x)
//{
//    post("value is %ld",x->s_value);
//}
//
//void makeDateName_float(t_makeDateName *x, double f)
//{
//    post("got a float and it is %.2f", f);
//}
