
from django.http.response import Http404
from django.template import context
from mysite.poll.models import Question
from django.shortcuts import get_object_or_404, render

# Create your views here.

from django.http import HttpResponse
from django.template import loader

def index(request):
    latest_question_list = Question.objects.order_by("-pub_date")[:5]
    context = {'latest_question_list': latest_question_list,}

    return render(request, 'poll/index.html',context)

def detail(request, question_id):

    question =  get_object_or_404(Question,pk=question_id)

    return render(request, 'poll/detail.html', {'question':question})


def results(request, question_id):
    response = "Your result of question: %s"
    return HttpResponse(response % question_id)

def vote(request, question_id):
    return HttpResponse("You are voting on question: %s " % question_id)
