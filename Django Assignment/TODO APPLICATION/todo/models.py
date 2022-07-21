from django.db import models
from django.conf import settings
from django.utils import timezone

# Create your models here.

class Task(models.Model):
    title = models.CharField(max_length=250)
    note = models.TextField()
    created_date = models.DateTimeField(default=timezone.now)
    finished_date = models.DateTimeField(blank=True, null=True)
    status = models.BooleanField(default=False,null=True)

    def __str__(self):
        return self.title