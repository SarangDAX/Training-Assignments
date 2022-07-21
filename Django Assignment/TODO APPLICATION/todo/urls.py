
from django.urls import path
from . import views

urlpatterns = [
    path('', views.Task_list, name='Task_list'),
    path('add/', views.add_task, name='add_task'),
    path('del_task/?P<int:id>', views.del_task, name='del_task'),
    path('update_task/?P<int:id>', views.update_task, name='update_task'),

]
                                      