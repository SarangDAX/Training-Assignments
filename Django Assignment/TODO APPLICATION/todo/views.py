from django.shortcuts import render,redirect

from todo.forms import PostForm
from .models import Task
from django.utils import timezone

# Create your views here.

def Task_list(request):
    tasks = Task.objects.filter(created_date__lte=timezone.now()).order_by('finished_date')
    return render(request, 'Task/Task_list.html', {'tasks':tasks})

def add_task(request):
    if request.method=='GET':
        return render(request, 'Task/add_task.html', {'form':PostForm()})
    else:
        form = PostForm(request.POST)
        try:
            tmp = form.save(commit=False)
            tmp.save()
        except:
            return redirect('Task_list')
        return redirect('Task_list')

def del_task(request,id):
    Task.objects.filter(id = id).delete()
    return redirect('Task_list')

def update_task(request,id):
    obj = Task.objects.filter(id = id)
    if obj[0].status == True:
        obj.update(status = False)
    else:
        obj.update(status = True)
    return redirect('Task_list')
    