from django import forms
from .models import Task
from django.forms import ModelForm

class PostForm(forms.ModelForm):
    class Meta:
        model = Task
        fields = ['title', 'note','finished_date']