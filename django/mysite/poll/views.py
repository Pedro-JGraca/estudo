
from django.views import generic
from .models import Question, Choice
from django.shortcuts import get_object_or_404, render
from django.urls import reverse

# Create your views here.

from django.http import HttpResponseRedirect

class IndexView(generic.ListView):
    template_name = 'poll/index.html'  #<app name>/<model name>_list.html
    context_object_name = 'latest_question_list'

    def get_queryset(self):
        """Return the last five published questions. """
        return Question.objects.order_by('-pub_date')[:5]

class DetailView(generic.DetailView):
    model = Question
    template_name = 'poll/detail.html' #<app name>/<model name>_detail.html

class ResultsView(generic.DetailView):
    model = Question
    template_name = 'poll/results.html'

def vote(request, question_id):
    question = get_object_or_404(Question, pk=question_id)
    try:
        selected_choice = question.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):

        return render(request, 'poll/detail.html', {
            'question': question,
            'error_message': "You didn't select a choice.",
        })
    else:
        selected_choice.votes += 1
        selected_choice.save()
    return HttpResponseRedirect(reverse('poll:results', args=(question.id,)))