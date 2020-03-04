#ifndef DEF_TASK
#define DEF_TASK

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Task
{
    public : 

        Task(std::string title, std::string description, int priority);
        void end_task();
        void change_priority(int n); 
        void advencement();
        void create_under_task(int id, std::string title, std::string description, int priority);
        void change_over_task(Task*);

    private : 

        int m_id;
        std::string m_title;
        std::string m_description;
        time_t m_creation_date;
        time_t m_closing_date;
        std::string m_status;
        int m_percentage;
        int m_priority; //priorité sont dans N* et commence à 1, priorité 1 étant la plus importante
        std::string m_commentary_file; //Spécifie le chemin vers le fichier texte des commentaires donc doit commencer par "C:\Users\maxca\Info\Coursc++\Projet"
        std::string m_backup_file;
        std::vector<Task*> m_under_tasks;
        Task* m_over_task;
        
};  



#endif