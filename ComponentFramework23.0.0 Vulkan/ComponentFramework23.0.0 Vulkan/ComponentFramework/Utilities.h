#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>

namespace VkUtilities
{
	//In Vulkan, there are a lot of structs being created in order to use in other structs, pass them to function calls, and do other things like that.
	//Thier presence in VulkanRenderers (relatively) higher level function calls makes those calls much harder to read, so I'm creating a bunch of helper functions so 
	//I can move them here.

    // I think I might want to eventually create structs in VkConcepts to pass into these

    //Reminder: we are creating a bunch of copies this way and its slow AF. Strongly consider doing something slightly less screwey.

    VkDescriptorSetLayoutBinding CreateDescriptorBinding(uint32_t binding_, uint32_t descriptor_count_, VkDescriptorType descriptor_type_, VkShaderStageFlagBits stage_flags_)
    {
        VkDescriptorSetLayoutBinding result{};
        result.binding = binding_;
        result.descriptorCount = descriptor_count_;
        result.descriptorType = descriptor_type_;
        result.pImmutableSamplers = nullptr;
        result.stageFlags = stage_flags_;
        return result;
    }

    auto CreatePipeLineinfo(VkStructureType stype_, VkShaderStageFlagBits stage_, VkShaderModule module_, const char* pName_)
    {
        VkPipelineShaderStageCreateInfo result{};
        result.sType = stype_;
        result.stage = stage_;
        result.module = module_;
        result.pName = pName_;
        return result;
    }

    auto CreateSubmitInfo(VkStructureType stype_, uint32_t waitSemaphoreCount_, VkSemaphore waitsemaphores_[], VkPipelineStageFlags waitstages_[], uint32_t commandbuffercount_, const VkCommandBuffer* commandbuffer_, VkSemaphore signalsemaphores_[], uint32_t signalsemaphcount_)
    {
        VkSubmitInfo result{};



        result.sType = stype_;

        
        result.waitSemaphoreCount = waitSemaphoreCount_;
        result.pWaitSemaphores = waitsemaphores_;
        result.pWaitDstStageMask = waitstages_;

        result.commandBufferCount = commandbuffercount_;
        result.pCommandBuffers = commandbuffer_;

       
        result.signalSemaphoreCount = signalsemaphcount_;
        result.pSignalSemaphores = signalsemaphores_;

        return result;
    }

    auto createpresentinfo(VkStructureType stype_, uint32_t waitsemaphorecount_, VkSemaphore waitsemaphores_[], uint32_t swapchaincount_, VkSwapchainKHR swapchains_[],  uint32_t* imageindex_)
    {
        VkPresentInfoKHR presentInfo{};
        presentInfo.sType = stype_;

        presentInfo.waitSemaphoreCount = waitsemaphorecount_;
        presentInfo.pWaitSemaphores = waitsemaphores_;

        
        presentInfo.swapchainCount = swapchaincount_;
        presentInfo.pSwapchains = swapchains_;

        presentInfo.pImageIndices = imageindex_;
        return presentInfo;
    }
    auto createappinfo(VkStructureType stype_, const char* appname_, uint32_t appversion_, const char* enginename_, uint32_t engineversion_, uint32_t apiversion_)
    {
        VkApplicationInfo result{};
        result.sType = stype_;
        result.pApplicationName = appname_;
        result.applicationVersion = appversion_;
        result.pEngineName = enginename_;
        result.engineVersion = engineversion_;
        result.apiVersion = apiversion_;
        return result;
    }

    auto createinstanceinfo(VkStructureType stype_, VkApplicationInfo* appInfo, uint32_t extensioncount_, const char* const* extensionnames_)
    {
        VkInstanceCreateInfo result;
        result.sType = stype_;
        result.pApplicationInfo = appInfo;
        result.enabledExtensionCount = extensioncount_;
        result.ppEnabledExtensionNames = extensionnames_;
        return result;
    }
}
